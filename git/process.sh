# Step 0. One time setup upstream, upstream can be renamed as anything like Paddle-official
git remote add upstream https://github.com/.../Paddle.git
git fetch upstream

# How to start making contribution

# Step 1. Get the updated codes
# 1a. 
git checkout {develop}
# 1b. 
git pull upstream {develop}

# Step 2. create a branch to work on: 
git checkout -b {branch}
# You will make serveral commits

# How to pull request {branch}
# 2.1 Create for_merge to solve conflicts
git checkout -b for_merge

# Step 3. 
git checkout {branch}

# Step 4. Merge latest codes with current version
git rebase -i for_merge
# 4a. solve conflict
# 4b. add solved files
git add ...
# 4c. 
git rebase --continue
# *** never do rebase on any branches that shared by other developers
# * you can abort at anytime by 
git rebase --abort

# After your pull request is merged, your contribution will be included in upstream {develop}. 

# Step 5. In addition, you can update the content for your fork repo: 
# 5a. 
git checkout develop
# 5b. 
git push origin develop

git branch -d for_merge
