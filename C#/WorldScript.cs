using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;
public class WorldScript : MonoBehaviour {

    public GameObject fish;
    public bool gameOver;
    public bool death;
    public GameObject deathAnimation;
    private Vector3 deathLocation;
    public GameObject clone;
    private bool DSpawn;
    public PlatformGenerator camera;
    public deathmenu deathMenu;
    public int distance;
    public Text distancetracker;
    public PlayerController fishPlayer;
    public GameObject ambience;
    public AudioClip dieFish;
    public AudioSource soundPlay;
    public GameObject distanceText;


    // Use this for initialization
    void Start () {
        death = false;
        DSpawn = true;
        gameOver = false;
        camera = GameObject.FindGameObjectWithTag("MainCamera").GetComponent<PlatformGenerator>();
        fishPlayer = GameObject.FindGameObjectWithTag("Fish").GetComponent<PlayerController>();
        distance = 0;
    }
	
	// Update is called once per frame
	void Update () {
        // If the game is not over, outputs the players current score
        if (!gameOver)
        {
            distance = distance + 1 * Mathf.RoundToInt(fishPlayer.speed);
            distancetracker.text = distance.ToString() + "km";
        }

        if (gameOver)
        {
           // SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex);
            Debug.Log("Build Bazoogi Tough");
            //Turns off the score output
            distanceText.SetActive(false);

            //Plays sound effects and gets the fishes location at the time of death
            if (!death)
            {
                soundPlay.clip = dieFish;
                soundPlay.Play();
                deathLocation = fish.transform.position;
                death = true;
            }
            //Destroys fish
            Destroy(fish);

            //Initiates the death animation
            if (DSpawn)
            {
                clone = Instantiate(deathAnimation, deathLocation, Quaternion.Euler(0, 0, 0));
                DSpawn = false;
            }

            //Activates the end game menu
            deathMenu.gameObject.SetActive(true);

            //Removes ambience sound
            Destroy(ambience);

        }
	}
}
