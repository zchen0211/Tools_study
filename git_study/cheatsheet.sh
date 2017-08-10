# 1. Basics
git log # see history, with commits id
git log --stat # history with changes of files
git diff old_ci_id1 new_ci_id2 # check diff between different commits
git checkout id # checkout and recover to a special commit

git config --global core.editor "subl -n -w"
git config --global push.default upstream
git config --global merge.conflictstyle diff3
git config --global user.email "chenzhuoyuan07@gmail.com"

git pull # pull all files, update to the latest version

# in case of conflicts, will be pulled
git commit -a -m "xxxxx" # local update

git status # check file status

# difference between working drectory and staging area
git diff
# check difference between staging area (git-added file before commit)
# and latest commit
git diff --staged

# reset all changes in staged and working 
git reset --hard

# stay in branch1 first!
git merge branch1 branch2
# merge all changes of branch2 into branch1
