# Các bước push Git 
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
