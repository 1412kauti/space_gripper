import pybullet as p
import time
import pybullet_data
physicsClient = p.connect(p.GUI)#or p.DIRECT for non-graphical version
p.setAdditionalSearchPath(pybullet_data.getDataPath()) #optionally
p.setGravity(0,0,-10)
planeId = p.loadURDF("plane.urdf")
cubeStartPos = [0,0,0]
cubeStartOrientation = p.getQuaternionFromEuler([0,0,0])
robotId = p.loadURDF("hand_assembly.urdf",cubeStartPos, cubeStartOrientation, 
                   # useMaximalCoordinates=1, ## New feature in Pybullet
                   flags=p.URDF_USE_INERTIA_FROM_FILE)

# Create sliders for each joint in degrees
num_joints = p.getNumJoints(robotId)
sliders = []
for joint_index in range(num_joints):
    joint_info = p.getJointInfo(robotId, joint_index)
    min_limit = joint_info[8]  # Minimum limit in radians
    max_limit = joint_info[9]  # Maximum limit in radians
    
    # Convert limits to degrees
    min_limit_deg = min_limit * (180.0 / 3.141592653589793)
    max_limit_deg = max_limit * (180.0 / 3.141592653589793)
    
    # Create a slider for the joint in degrees
    slider = p.addUserDebugParameter(joint_info[1].decode('utf-8'), 
                                      min_limit_deg, max_limit_deg, 
                                      min_limit_deg)  # Default to min position
    sliders.append(slider)

for i in range (10000):
    p.stepSimulation()
    
    # Update joint positions based on slider values
    for joint_index in range(num_joints):
        joint_value_deg = p.readUserDebugParameter(sliders[joint_index])
        
        # Convert the degree value back to radians for control
        joint_value_rad = joint_value_deg * (3.141592653589793 / 180.0)
        
        p.setJointMotorControl2(robotId, joint_index, p.POSITION_CONTROL, targetPosition=joint_value_rad)

    time.sleep(1./240.)
cubePos, cubeOrn = p.getBasePositionAndOrientation(robotId)
print(cubePos,cubeOrn)
p.disconnect()

