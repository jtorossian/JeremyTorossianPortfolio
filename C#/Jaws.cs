using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Jaws : MonoBehaviour
{
    public Stage stage;
    private bool start = false;
    public float speed;
    public bool done = false;
    private Vector3 updatedPosition;
    public Animator animator;
    public GameObject indicator;
    private GameObject clone;
    public GameObject cloneDestory;
    private bool spawn;
    public AudioClip earthquake;
    public AudioClip bite;
    public AudioClip indicatorS;
    public AudioSource soundPlay;
    public bool shakeSound;
    public bool indicatorSound;


    void OnTriggerEnter2D(Collider2D collision)
    {
        //Kills fish if collision is made
        if (collision.gameObject.tag == "Fish")
        {

            soundPlay.clip = bite;
            soundPlay.Play();
            animator.SetBool("Bite", true);
            animator.SetBool("Up", false);
            animator.SetBool("Up", false);
        }
    }
    // Use this for initialization
    void Start()
    {
        spawn = true;
        indicatorSound = true;

    }

    // Update is called once per frame
    void Update()
    {
        if (stage.stop) //Checks if stage is on the same track as the camera
        {
            // Spawns the indicator while also preparing the sound effects to be played
            if (spawn)
            {
                if(indicatorSound)
                {
                    soundPlay.clip = indicatorS;
                    soundPlay.Play();
                    indicatorSound = false;
                }
                clone = Instantiate(indicator, new Vector3(transform.position.x, transform.position.y + 10.5f, transform.position.z), Quaternion.Euler(0, 0, 0), transform.parent);
                clone.transform.localScale = new Vector3(0.028125F, .05f, .05f);

                shakeSound = true;
                spawn = false;
            }

            StartCoroutine("moving");
            //Starts sound effects
            if (shakeSound)
            {
                soundPlay.PlayOneShot(earthquake, 1);
                shakeSound = false;
            }
        }

        //initiated the movement
        if (start && !done)
        {
            //Destroys the indicator once the shark reaches a certain point
            if (transform.position.y > -12f)
            Destroy(clone);

            updatedPosition = new Vector2(transform.position.x, -2.8f);
            animator.SetBool("Up", true);

            //Moves the shark
            transform.position = Vector2.MoveTowards(new Vector2(transform.position.x, transform.position.y), updatedPosition, speed * Time.deltaTime);

            //Once shark reaches its peak starts the exit courtine
            if(transform.position == updatedPosition)
            {
                StartCoroutine("exit");
            }
        }

        if(done) // initiates the shark leaving
        {
            //Moves the shark back down
            updatedPosition = new Vector2(transform.position.x, -13f);
            transform.position = Vector2.MoveTowards(new Vector2(transform.position.x, transform.position.y), updatedPosition, speed * Time.deltaTime);

            //Removes stage from camera track
            if (transform.position == updatedPosition)
            {
                stage.stop = false;
            }
        }
    }

    //Both corutines have the program wait one second before moving on to the next part of the script
    IEnumerator moving()
    {
        Debug.Log("Co Routine start");
        yield return new WaitForSeconds(1f); 
        start = true;
        Debug.Log("Co Routine end");

    }

    IEnumerator exit()
    {
        Debug.Log("Co Routine start");
        yield return new WaitForSeconds(1f); 
        done = true;
        Debug.Log("Co Routine end");

    }
}