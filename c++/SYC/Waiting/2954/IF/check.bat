@echo off
:loop
    Random\std.exe> data.in
    std\std.exe < data.in > std.answer
    me\std.exe < data.in > me.answer
    fc std.answer me.answer
    if not errorlevel 1 goto loop
pause
goto loop
