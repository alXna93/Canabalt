#pragma once

// Library includes
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class AssetManager
{

public: 

	//public interface / behaviours

	//Constructor
	AssetManager();

	//Get a texture based on a file name
	static sf::Texture& GetTexture(std::string _fileName);

	////Get a sound buffer based on a file name
	//static sf::SoundBuffer& GetSoundBuffer(std::string _fileName);

	////Get a font based on a file name
	//static sf::Font& GetFont(std::string _fileName);


private:

	// Private data for this class

	// Pointer to the class itself
	// For the singleton design pattern
	// The one and only instance of this class
	static AssetManager* s_instance;

	// List of textures
	std::map<std::string, sf::Texture> m_textures;
	// List of sound buffers
	std::map<std::string, sf::SoundBuffer> m_soundbuffers;
	// List of fonts
	std::map<std::string, sf::Font> m_fonts;
};