import psutil

PROCNAME = "battery-monitor.exe"

for proc in psutil.process_iter():
    # check whether the process name matches
    if proc.name() == PROCNAME:
        proc.kill()

# pyinstaller --onefile --windowed exit.py