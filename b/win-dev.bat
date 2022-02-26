@echo off
del bin\gn
bin\gn.exe gen out\win-x64-debug --args="skia_use_angle=true target_cpu=\"x64\"" --ide=vs 
ninja -C out/win-x64-debug HelloWorldApp

echo.
echo Run Test:
echo out/win-x64-debug/HelloWorldApp
echo out/win-x64-debug/TemplateApps
echo out/win-x64-debug/ImageTest
echo out/win-x64-debug/TouchApp
echo.

