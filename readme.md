### ROOT study  
#### purpose:  
#### 1) Basic usages of ROOT  
#### 2) ROOT with c++ or python  
#### 3) Embeded ROOT  
---
### Basic usage of github

#### Initial Setting: We need this to start git  
#### >git config --global user.name "Your Name Here"  
#### >git config --global user.email "your_email@youremail.com"  
  
#### Cloning the existed repository in github  
#### >git clone address-of-the-repository  
: copy the repository from the github to your loacl cpu  
  
#### Making your own local repository  
#### I assume that you aleady make the online repository on github  
#### >git init  
: Initialize the directory to use the git command  
#### >git remote add origin address-of-the-online-repository  
: It connect the online repository and your local repository  
#### >git add files-to-uploaded  
#### >git commit  
#### >git push  (use "git push origin master" when you first upload the files)
: This make the files to updated on github  
#### >git pull  
: Update the repository  
: It makes your local repository become same condition to your online repository(git hub)  
  
---

### Key gen: auto log-in  
>cd ~/.ssh  
>ssh-keygen  
Enter Enter....  
>ls  
  
id_dsa.pub: public key  
copy this and paste to github/your profile/Edit profile/SSH
---

