<img width="1149" height="253" alt="image" src="https://github.com/user-attachments/assets/c4e4d065-04b4-4742-8d9c-271239d307be" /># Các bước push Git 
```c
git init
git add .
git commit -m "first commit"
git branch -M main
git remote add origin https://github.com/DuyHuynh284/ADVANCED_C.git
git push -u origin main
```
# Trường hợp từ chối push do có file trước đó 
```c
git init
git add .
git commit -m "first commit"
git branch -M main
git remote add origin https://github.com/DuyHuynh284/ADVANCED_C.git
git pull origin main --allow-unrelated-histories
git push -u origin main
```
## Cách thoát màn hình xanh 
```c
git pull origin main --allow-unrelated-histories
```
### Làm theo các bước sau
```
ESC
:wq
Enter
```
#### push 1 folder
```
git pull
git add L3_Bitmask
git status
git commit -m "add L3 bitmask lesson"
git push
```
#### push 1 file
```
git pull origin main
git add "<Folder>/<File>"
git commit -m "update <file or feature>"
git push origin main
```
### get code from another github
```
B1: open cmd
B2: cd Project_Folder
B3: git clone https://github.com/user/repo.git
B4: build and run
```
