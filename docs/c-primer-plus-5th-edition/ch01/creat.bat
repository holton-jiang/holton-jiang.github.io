@echo off
echo ==============================================
echo 开始编译 Ocalc
echo ==============================================

gcc ^
count.c app.res.o ^
-o Ocalc ^
-O3 -s -static -static-libgcc -static-libstdc++ -fno-stack-protector ^
-lgdi32 -luser32 -lshell32 -lshlwapi -lsetupapi -ldxgi -lkernel32 -ladvapi32 -lm

echo.
if exist Ocalc.exe (
    echo 编译成功！生成文件: Ocalc.exe
) else (
    echo 编译失败！请检查代码或编译环境
)
pause