//Library includes
#include <assert.h>

//Project includes
#include "AssetManager.h"

//Initialise the static reference to our instance - to nullptr (aka zero)
AssetManager* AssetManager::s_instance = nullptr;

//Constructor
AssetManager::AssetManager()
	: m_textures()
	, m_soundbuffers()
	, m_fonts()

{
	//Throw and error and stop execution (in debug mode) if a copy
	//of this class has already been created
	assert(s_instance == nullptr);

	//Assign ourselves to the instance pointer
	// - this is the new instance of the class that has just been created
	s_instance = this;
}


sf::Texture& AssetManager::GetTexture(std::string _fileName)
{
	//create an iterator to hold a key and value pair
	//and search for the required key
	//using the passed in file name
	auto keyValuePair = s_instance->m_textures.find(_fileName);
	// "auto" in this case is equivalent to writing 
	//std::map<std::string,sf::Texture>::iterator
	//This keyword (auto) can be used in cases where the compiler can figure out the type oof a variable for you
	//YOU ARE NOT ALLOWED TO USE THIS EXCEPT FOR ITERATORS
	
	//did we find the texture? (aka was it already loaded?)
	//(iterator will be at the end if we did NOT find it)

	if (keyValuePair != s_instance->m_textures.end())
	{
		//YES! We found it!
		return keyValuePair->second;
	}
	else
	{
		//No we didnt find it
		//Lets create it then

		//create a new key value pair using the filename
		//the subscript [] operator creates and entry in the map 
		//if there is not already one there

		sf::Texture& texture = s_instance->m_textures[_fileName];
		//blank texture has been created 
		//now just load it from file using SFML

		texture.loadFromFile(_fileName);

		//return the texture to the calling code
		return texture;
	}
}