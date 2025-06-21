@echo off
g++ main.cpp Matrix.cpp Methods.cpp menu.cpp utils.cpp validations.cpp -o LinSys.exe
if errorlevel 1 (
    echo Error al compilar
) else (
    echo Compilación exitosa.
    Calculadora.exe
)
pause
