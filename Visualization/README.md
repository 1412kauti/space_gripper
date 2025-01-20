![Robot](https://github.com/1412kauti/space_gripper/blob/main/Visualization/images/robot.png)
# URDF File

`graph.txt` contains how the links and joints are deined, visit [here](http://www.webgraphviz.com/) and paste the following text to generate the graph

(Purely for visualization)

```
digraph G {  "base_link" -> "side_1_1" [ label = "side_1_joint" ] 
  "side_1_1" -> "finger1_0_1" [ label = "finger_1_1_joint" ] 
  "finger1_0_1" -> "finger1_1_1" [ label = "finger_1_2_joint" ] 
  "finger1_1_1" -> "finger1_2_1" [ label = "finger_1_3_joint" ] 
  "base_link" -> "side_2_1" [ label = "side_2_joint" ] 
  "side_2_1" -> "finger2_0_1" [ label = "finger_2_1_joint" ] 
  "finger2_0_1" -> "finger2_1_1" [ label = "finger_2_2_joint" ] 
  "finger2_1_1" -> "finger2_2_1" [ label = "finger_2_3_joint" ] 
  "base_link" -> "side_3_1" [ label = "side_3_joint" ] 
  "side_3_1" -> "finger3_0_1" [ label = "finger_3_1_joint" ] 
  "finger3_0_1" -> "finger3_1_1" [ label = "finger_3_2_joint" ] 
  "finger3_1_1" -> "finger3_2_1" [ label = "finger_3_3_joint" ] 
}
```
![Links and Joints](https://github.com/1412kauti/space_gripper/blob/main/Visualization/images/graph.png)
# Using the URDF Files

Copy the `hand_assembly.urdf` and `meshes` folder to your project to import the urdf as usual using either MujuCo
, URDF-VIZ or PyBullet

# Viewing the URDF
## URDF-VIZ
### Windows
```
cd /path/to/project
urdf-viz.exe hand_assembly.urdf
```
### Linux and MacOS
Download the Binary from [here](https://github.com/openrr/urdf-viz/releases/tag/v0.46.1)
and extract the binary in the same project folder and then

```
cd /path/to/project
./urdf-viz hand_assembly.urdf
```

## PyBullet

> Recommended to use a Virtual Environment (conda, mamba, venv, uv, ... etc)

```
conda create -n pybullet_env python=3.9
conda activate pybullet_env
conda install -c conda-forge pybullet
python pybullet_sim.env
```

## MujuCo (Broilerplate)

WiP




