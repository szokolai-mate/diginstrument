#pragma once

#include <vector>

#include <iSource.h>

namespace Mixer{
    //! \~english Interface for different audio backends.
    //! \~hungarian Különböző audió backendekhez tartozó interfész.
    template <typename T>
    class iAudioBackend{
    public:
        /*!
            \~english Initializes the audio backend into a playable state. Should not begin playing.
            \~hungarian Felkészíti a backendet lejáttszásra. Nem indítja el a lejátszást.
            \~english \param source the source of the audio data
                            \~hungarian \param source az audió adat forrása
           \~english  \param channels the channel count of the audio data
                            \~hungarian  \param channels az audió adat csatornáinak száma
            \~english \param sampleRate the sample rate of the audio data
                            \~hungarian \param sampleRate az audió adat mintavételezési sűrűsége 
            
            \~english \return wether initialization was successful
                    \~hungarian \return az inicializáció sikeres volt-e
        */
        virtual bool init(DataFlow::iSource<T> & source, const unsigned int & channels, const unsigned int & sampleRate) = 0;
        virtual ~iAudioBackend(){};
    };
};