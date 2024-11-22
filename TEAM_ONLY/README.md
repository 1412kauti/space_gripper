This page is intended purely for internal documentation and MAY or MAY NOT be used for any of our submissions.

Here's a few steps for those unaware of how GitHub works

## Step 1. Create Access Tokens
1. Go To [GitHub](https://github.com/)
2. **Sign-In**
3. On the Top Right Corner, **Profile** -→ **Settings**
4. On the Left Pane,  **Developer Settings** -→ **Personal Access Tokens** -→ **Tokens(classic).**
5. Click on **Generate New Token** -→ **Generate New Token(Classic)**
6. In the following Page:
	a. Give a name to this Access Token in **Note** section.
    b. Set an **Expiry** for this, personally I use a **No expiration** but its is usually recommended to go for a set number of days Eg: 30 days.
    c. I usually check mark everything, so that I have full access of my GitHub Account from the terminal.
7. Click on **Generate Token**.
8. This will generate a code, copy this code and store it in a very very very safe place (No not in a Notepad .txt file)

## Cloning the Repo
> Windows: make sure to install [git](https://git-scm.com/downloads) and make sure its added to the PATH.
1. Open **Terminal** (Windows Terminal/ Bash/ Fish / Zsh Shell ).
2. (Optional) Create a new Folder or Change directory to your desired location using
> `mkdir` is a short for "Make Directory" and `cd` is a short for Change Directory
> 
```
mkdir all_repos
# or
mkdir /path/to/all_repos (might not work in windows)
```

or 
```
cd all_repos
# or
cd /path/to/all_repos 
```

3. Clone repo using:
```
git clone https://github.com/1412kauti/space_gripper.git
```
4. This will prompt for a username, use your github username (NOT THE EMAIL) and press `Enter/Return`.
5. For the password, paste the Personal Access Token (PAT) from the previous step. (No Not your Github Password...it wont work)

## Contributing to the Project:

1. After cloning the project, `cd` into the cloned project:
```
cd space_gripper
```
2. Get all the previous changes:
```
git pull
```
3. leave the terminal(No Do'nt close it),  Make a few changes to the project (IDK...add theory pdf/docx files or Matlab files,etc in their respective folders using Windows Explorer/ Mac Finder / Nautilus)
4. now come back to the same Terminal and add the changed files for a commit using: (NOTE: Empty Folders are not added)
```
git add .
```
5. Commit the changes along with a message using:
```
git commit -m "Message of the Day...LOL"
```
6. Push changes using
```
git push
```