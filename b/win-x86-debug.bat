rm bin\gn
bin\gn.exe gen out\win-x86-debug --args="target_cpu=\"x86\"" 
echo ""
echo "Build cmd:"
echo "ninja -C out/win-x86-debug"
echo ""
echo "Run Test:"
echo "out/win-x86-debug/HelloWorld"
echo ""
pause
