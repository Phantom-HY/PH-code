@echo off
cd %~dp0
:loop
    @REM Random生成样例
    @REM std暴力代码
    @REM me自己要测试的代码
    Random\std.exe> data.in
    std\std.exe < data.in > std.answer
    me\std.exe < data.in > me.answer
    fc std.answer me.answer
    if not errorlevel 1 goto loop
pause
goto loop