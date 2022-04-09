del bin\gn
bin\gn.exe gen out\win-x64-debug --args="target_cpu=\"x64\"" --ide=vs 
echo off
echo -------------------------
echo Build cmd:
echo ninja -C out/win-x64-debug HelloWorldApp
echo ninja -C out/win-x64-debug DemoApp
echo -------------------------
echo Run Test:
echo out/win-x64-debug/HelloWorldApp
echo out/win-x64-debug/DemoApp
echo -------------------------

