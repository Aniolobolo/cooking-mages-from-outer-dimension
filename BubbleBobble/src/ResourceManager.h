#pragma once

#include "raylib.h"
#include "Globals.h"
#include <unordered_map>
#include <string>

enum class Resource {
    IMG_MENU,
    IMG_INSERTCOIN,
    IMG_CREDITS,
    IMG_PROFESSORS,
    IMG_ACLARATION,
    IMG_GAMEWON,
    IMG_GAMEOVER,
    IMG_PLAYER,
    IMG_PLAYER2,
    IMG_ZENCHAN,
    IMG_INVADER,
    IMG_SHOTINVADER,
    IMG_MIGHTA,
    IMG_SHOTMIGHTA,
    IMG_DRUNK,
    IMG_SHOTDRUNK,
    IMG_BUBBLE,
    IMG_TILES,
    IMG_ITEMS
};

class ResourceManager {
public:
    //Singleton instance retrieval
    static ResourceManager& Instance()
    {
        static ResourceManager instance; //Guaranteed to be initialized only once
        return instance;
    }

    //Load and unload texture
    AppStatus LoadTexture(Resource id, const std::string& file_path);
    void ReleaseTexture(Resource id);

    //Get texture by key
    const Texture2D* GetTexture(Resource id) const;

    //Release resources
    void Release();

    //Ensure Singleton cannot be copied or assigned
    ResourceManager(const ResourceManager&) = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;

private:
    //Private constructor to prevent instantiation
    ResourceManager();
    //Destructor
    ~ResourceManager();

    //Dictionary to store loaded textures
    std::unordered_map<Resource, Texture2D> textures;
};