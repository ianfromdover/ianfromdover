From https://www.youtube.com/watch?v=QCG_ov0R51U
YOU NEED TO BE NEW USER RANK, NOT VISITOR TO UPLOAD AVATARS

# Steps
1. Download all the shit. Currently I'm using
    - [Unity 2019.4.31f1](https://docs.vrchat.com/docs/current-unity-version)
    - [VRChat Avatar SDK](https://vrchat.com/home/download): to upload to vrchat
    - [UniVRM v0.98.0 2f6b](https://github.com/vrm-c/UniVRM/releases): vrm importer for vrchat
    - [Pumkin's Avatar Tools v1.1](https://github.com/rurre/PumkinsAvatarTools): for posing and view adjustment (fork to update docs?)
Note: you should have your exported .vrm avatar model ready to import
For shoulder and leg fixes: https://www.youtube.com/watch?v=Qbwl9XIONuQ
- [VRM Blender importer](https://github.com/saturday06/VRM_Addon_for_Blender)
- [Cat's Blender plugin for blender 2.8+](https://github.com/absolute-quantum/cats-blender-plugin)

# Get the model into unity
2. Import VRChat SDK
3. Import VRM Converter
4. top menu bar > VRM0 > Import From VRM 0.x
5. Drag the prefab onto scene's 0, 0, 0
6. With the prefab in hierarchy selected, VRM0 > Duplicate and convert for VRChat
7. In pop-up, 'duplicate and convert' button. save the next pop up too

# Refine the model
8. In your hierarchy, open the VRC Avatar Descriptor of the new prefab, open the View drop down.
9. Move the grey ball in between the character's eyes, thats where the camera will be.
    - (if there is no grey ball, make a sphere yourself in the hierarchy and place it between the eyes, then copy its position from its transform component).
    - after pasting into the view place, delete the sphere

optional. use pumpkin's avatar tools to pose your avatar.

# Upload to VRChat
10. top menu bar > VRChat SDK
11. login
optional. If your avatar has less than 15000 polygons, you can build for quest. Switch build target to android.
12. builder > publish
