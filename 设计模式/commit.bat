@echo off
REM 获取当前时间并格式化
for /f "tokens=1-5 delims=:. " %%a in ("%time%") do set hour=%%a& set min=%%b& set sec=%%c& set ampm=%%d
for /f "tokens=1-3 delims= " %%a in ("%date%") do set day=%%a& set month=%%b& set year=%%c
set timestamp=%year%-%month%-%day% %hour%:%min%:%sec%

REM 进入当前目录
cd /d "%~dp0"

REM 添加所有变动
git add .

REM 提交更改
git commit -m "Commit at %timestamp%"

REM 推送到远程仓库
git push origin master

pause
