@echo off

REM Путь к программе через первый аргемент 
SET Program="%~1"

REM Защита от запуска без аргумента, задающего путь к программе 
if %Program%=="" (
	echo Please specify path to Program
	exit /B 1
)

REM If output file is not specified, program msut fail
%Program% MissingFile.txt && goto err
echo If output file is not specified, program msut fail
echo Test 1 passed

REM If input and output files are not specified, program must fail
%Program% && goto err
echo If input and output files are not specified, program must fail
echo Test 2 passed

REM If input and output files are not specified, program must fail
%Program% MissingFile.txt "Я к вам пишу" "Я" && goto err
echo If input and output files are not specified, program must fail
echo Test 3 passed

REM Тесты пройдены 
exit /B 0

REM Тесты с ошибкой 
:err
echo Test failed
exit /B 1