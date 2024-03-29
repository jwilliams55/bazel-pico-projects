~/apps/openocd/bin/openocd -f interface/cmsis-dap.cfg -c "adapter speed 5000" -f target/rp2040.cfg -c "program bazel-bin/src/hello_world/hello-world.elf verify reset exit"
