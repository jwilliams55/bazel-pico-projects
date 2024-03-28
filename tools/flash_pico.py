import argparse
import subprocess
import sys

def flash_pico(file: str) -> bool:
    cmd = f"openocd -f interface/cmsis-dap.cfg -c 'adapter speed 5000' -f target/rp2040.cfg -c 'program {file} verify reset exit'"
    proc = subprocess.run(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True)
    if proc.returncode != 0:
        print(f"Error: {proc.stderr.decode()}")
        return False

    return True

def _parse_args():
    parser = argparse.ArgumentParser(description="Flash a Pico board")
    parser.add_argument("file", type=str, help="The file to flash")
    return parser.parse_args()

if __name__ == "__main__":
    args = _parse_args()

    suc = flash_pico(args.file)

    if not suc:
        sys.exit(1)
    sys.exit(0)
