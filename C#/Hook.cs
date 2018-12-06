using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Hook : MonoBehaviour {

    public WorldScript world;
    public int death = 0; //Death tracler
    private float move; //Gets the value that will determine if hook will move
    private bool moved; //Checks if hook has already been moved
    public int speed; 
    public bool startMove;
    private Vector3 updatedPosition;
    public Animator animator;
    public GameObject upZone;
    public AudioClip shake;
    public AudioSource soundPlay;
    public bool shakeSound;


    void OnTriggerEnter2D(Collider2D collision)
    {
        //Checks if collision was made with fish
       if (collision.gameObject.tag == "Fish")
        {
            ++death; //Marks up one and then destoys the initial collider attached to the hook, while also initiating the necessary audio.
            Destroy(upZone);
            startMove = true;
            shakeSound = true;
            if (death == 2) //If the fish hits the hooks second collider, kills fish
            world.gameOver = true;
        }
    }
    // Use this for initialization
    void Start () {
        moved = false;
        move = Random.Range(0.0f, 1.0f); //Gets the random loction the hook will go.
        world = GameObject.FindGameObjectWithTag("world").GetComponent<WorldScript>();
        transform.position = new Vector3(transform.position.x, Random.Range(-4f, 4f), 0); //Spawns hook on a random location on the Y axis
	}
	
	// Update is called once per frame
	void FixedUpdate () {

        if (startMove) //Starts move logic
        {
            if (move <= 0.4f && !moved ) //Moves the hook, only once, if the random value generated is greated than .4
            {
                updatedPosition = new Vector2(transform.position.x, 5f);
                if (shakeSound) //Place shake sound effect
                {
                    soundPlay.clip = shake;
                    soundPlay.Play();
                    shakeSound = false;
                }
                animator.SetBool("Move", true);
                StartCoroutine("moving");
            }
            if (moved) //Moves the hook
            {
                animator.SetBool("Move", false);
                transform.position = Vector2.MoveTowards(new Vector2(transform.position.x, transform.position.y), updatedPosition, speed * Time.deltaTime);
            }
        }

    }

    IEnumerator moving() //Waits 1 second before the hook is moved to allow the shake animation to play 
    {
        Debug.Log("Co Routine start");
        yield return new WaitForSeconds(1f); 
        moved = true;
        Debug.Log("Co Routine end");


    }

}
