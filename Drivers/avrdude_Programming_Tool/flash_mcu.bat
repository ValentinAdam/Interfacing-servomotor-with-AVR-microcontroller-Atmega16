@ECHO OFF

ECHO.
ECHO This script uses avrdude to program an AVR MCU.
ECHO The script asumes that the project name is identical to the project folder and that the script is called from within that folder.
ECHO.
ECHO Usage: flash_mcu.bat ^<TARGET_MCU^>
ECHO Example: flash_mcu.bat atmega328p
ECHO.

IF [%1] == [] (
	ECHO TARGET MCU NOT DEFINED! ^(usage: flash_mcu.bat ^<TARGET_MCU^>^)
	EXIT /B -1
) ELSE (
	SET TARGET_MCU=%1%
)
	
SET PROJ_PATH=%CD%
ECHO Project path: %PROJ_PATH%	

FOR %%I IN (%PROJ_PATH%) DO SET PROJ_DIR=%%~nxI
ECHO Project directory: %PROJ_DIR%

%PROJ_PATH%\tools\avrdude.exe -C %PROJ_PATH%\tools\avrdude.conf -c usbasp -p %TARGET_MCU% -B12 -U flash:w:%PROJ_PATH%\Debug\%PROJ_DIR%.hex:i
