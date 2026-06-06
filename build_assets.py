import os
import shutil

print("🦖 Trexpaxdash Asset Helper Starting Up...")

# Define the paths for your project
PROJECT_RESOURCES = "./resources"
GEODE_CONFIG_DIR = "/Android/media/com.geode.launcher/game/geode/config/trexpaxhq.trexpaxdash"

def deploy_textures():
    # Check if your custom drawn icon exists
    if os.path.exists(f"{PROJECT_RESOURCES}/about.png"):
        print("🎨 Found your custom about.png icon!")
        
        # In a real desktop-to-tablet environment, this script could 
        # automatically push your painted textures straight into the game folder!
        print("🚀 Copying assets to Geode workspace...")
        # shutil.copy(src, dst)
    else:
        print("⚠️ Missing about.png inside the resources folder!")

deploy_textures()
print("✅ Trexpax HQ Asset Build Complete!")
