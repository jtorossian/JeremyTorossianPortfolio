using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Zone : MonoBehaviour {
    public PlayerController fish;
    public Animator animator;
    public AudioClip mouth;
    public AudioSource soundPlay;
    public bool playCheck;

    //If the fish enter the zone, it sets the max speed to 6 to prevent fish from leaving the screen, then when the fish leave it sets it back to 12.
    //It also changes the shark sprite
    void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.gameObject.tag == "Fish")
        {
            fish.maxspeed = 6;
            animator.SetBool("Stage1", true);
        }
    }

    void OnTriggerStay2D(Collider2D collision)
    {
        if (collision.gameObject.tag == "Fish")
        {
            fish.maxspeed = 6;
            animator.SetBool("Stage1", true);
        }
    }


    void OnTriggerExit2D(Collider2D collision)
    {
        if (collision.gameObject.tag == "Fish")
        {
            fish.maxspeed = 12;
            animator.SetBool("Stage1", false);
        }
    }

    // Use this for initialization
    void Start () {
        fish = GameObject.FindGameObjectWithTag("Fish").GetComponent<PlayerController>();
    }
	
	// Update is called once per frame
	void Update () {
		
	}
}
