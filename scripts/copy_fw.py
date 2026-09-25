# scripts/copy_fw.py
Import("env")               # required so 'env' is available
import os, shutil

OUT = os.path.join(".pio", "build", "wokwi")
os.makedirs(OUT, exist_ok=True)

def _copy_to_wokwi(target, source, env):
    for ext in ("bin", "elf"):
        src = env.subst(f"$BUILD_DIR/${{PROGNAME}}.{ext}")
        if not os.path.exists(src):
            print(f"[wokwi] WARN: build artifact not found: {src}")
            continue
        dst = os.path.join(OUT, os.path.basename(src))
        shutil.copy2(src, dst)
        print(f"[wokwi] copied {src} -> {dst}")

# run after every build (even when the firmware is already up to date),
# so switching environments always updates what Wokwi runs
env.AddPostAction("buildprog", _copy_to_wokwi)
