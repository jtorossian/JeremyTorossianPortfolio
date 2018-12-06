using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Shark : MonoBehaviour {
    public PlayerController fish;
    private Rigidbody2D rb2d;       //Store a reference to the Rigidbody2D component required to use 2D Physics.
    public float speed;
    private Vector3 updatedPosition;
    public Animator animator;
    public AudioClip bite;
    public AudioSource soundPlay;


    void OnTriggerEnter2D(Collider2D collision)
    {
        //Kills the fish is collision is made
        if (collision.gameObject.tag == "Fish")
        {
            soundPlay.clip = bite;
            soundPlay.Play();
            animator.SetBool("Kill", true);
        }
    }

    // Use this for initialization
    void Start () {
        fish = GameObject.FindGameObjectWithTag("Fish").GetComponent<PlayerController>();
        rb2d = GetComponent<Rigidbody2D>();
    }
	
	// Update is called once per frame
	void Update () {
        speed = fish.speed;
        //Follows the fish on the Y axis
        if (fish)
        {
            updatedPosition = new Vector2(transform.position.x, fish.transform.position.y);
            transform.position = Vector2.MoveTowards(new Vector2(transform.position.x, transform.position.y), updatedPosition, speed * Time.deltaTime);
        }  
    }
}
