using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Audio;
using UnityEngine.UI;


public class Settings : MonoBehaviour {

    public AudioMixer mainAudio;
    public Toggle toggle;
    public Slider slider;
    public float currentVolume;
    public bool betweenScreen;

    void Awake()
    {
        //Sets the buttons to match the current settings of the game
        mainAudio.GetFloat("masterVolume", out currentVolume);
        slider.value = currentVolume;

        mainAudio.GetFloat("musicVolume", out currentVolume);

        if (currentVolume == -80)
            toggle.isOn = !toggle.isOn;
    }

    //Sound slider
    public void setVolume(float volume)
    {
        mainAudio.SetFloat("masterVolume", volume);
    }

    //Turns music on and off
    public void music(bool check)
    {
        if (check)
            mainAudio.SetFloat("musicVolume", 0);
        else if (!check)
            mainAudio.SetFloat("musicVolume", -80);

    }
}
