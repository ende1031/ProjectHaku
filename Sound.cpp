#include "Sound.h"

Sound::Sound()
{
}

Sound::~Sound()
{
	if (m_SoundEngine)
		m_SoundEngine->drop();
}

void Sound::Start()
{
	m_SoundEngine = irrklang::createIrrKlangDevice();
}

void Sound::PlayBGM(const char* soundFileName)
{
	if (m_SoundEngine)
		m_SoundEngine->play2D(soundFileName, true);
}

void Sound::PlaySE(const char* soundFileName)
{
	if (m_SoundEngine)
		m_SoundEngine->play2D(soundFileName, false);
}

void Sound::Stop()
{
	if (m_SoundEngine)
		m_SoundEngine->stopAllSounds();
}

void Sound::Pause()
{
	if (m_SoundEngine)
		m_SoundEngine->setAllSoundsPaused(true);
}

void Sound::Replay()
{
	if (m_SoundEngine)
		m_SoundEngine->setAllSoundsPaused(false);
}