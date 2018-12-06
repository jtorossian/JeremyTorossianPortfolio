using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bird : MonoBehaviour {

    public Despawner end;
    public PlatformGenerator camera;
    public bool mid;
    public BirdSpawner Spawn;
    public Vector3 startPosition;
    private Vector3 updatedPosition;
    Quaternion target;
    public float speed;
    private float location;
    private bool track;
    private bool Ispawn;
    private bool start;
    public GameObject indicator;
    private GameObject clone;
    public GameObject cloneDestory;
    public AudioClip dive;
    public AudioClip leave;
    public AudioClip[] indicatorS;
    public AudioSource soundPlay;
    public bool diveSound;
    public bool indicatorSound;


    void OnTriggerEnter2D(Collider2D collision)
    {
        //Destroys bird one it gets to despawners.
        if (collision.gameObject.tag == "Despawn")
        {
            Debug.Log("We Made it boys");
            Spawn.spawn = true;
            Destroy(gameObject);
        }

    }
    // Use this for initialization
    void Start()
    {
        camera = GameObject.FindGameObjectWithTag("MainCamera").GetComponent<PlatformGenerator>();
        end = GameObject.FindGameObjectWithTag("Despawn").GetComponent<Despawner>();
        Spawn = GameObject.FindGameObjectWithTag("BirdSpawner").GetComponent<BirdSpawner>();


        //transform.position = new Vector3(transform.position.x - Random.Range(0, 4), transform.position.y, 0);
        location = Random.Range(0.0f, 7.0f);
        mid = false;
        updatedPosition = new Vector2(transform.position.x - 2, Random.Range(0.0f, -2.6f));
        Ispawn = true;
        start = false;
        track = true;
        indicatorSound = true;
        diveSound = true;
    }

    // Update is called once per frame
    void Update()
    {
        //Spawns indicator and prepares sounds
        if (Ispawn)
        {
            if (indicatorSound)
            {
                soundPlay.clip = indicatorS[Random.Range(0, 5)];
                soundPlay.PlayOneShot(soundPlay.clip, .2f);
                indicatorSound = false;
            }

            clone = Instantiate(indicator, new Vector3(transform.position.x, transform.position.y, transform.position.z), Quaternion.Euler(0, 0, 180), transform.parent);
            clone.transform.localScale = new Vector3(.3f, .3f, 1);
            Ispawn = false;
        }

        //If stage is on track, spawns birds and prepares their location
        if (track)
        {
            transform.position = new Vector3(camera.transform.position.x +location, transform.position.y, transform.position.z);
            clone.transform.position = new Vector3(camera.transform.position.x + location, transform.position.y -3, transform.position.z);
            StartCoroutine("moving");
        }

        //Initiates the bird attack
        if (!mid && !track)
        {
            //Destroy indicators
            Destroy(clone);

            //Plays sound effect
            if (diveSound)
            {
                soundPlay.clip = dive;
                soundPlay.PlayOneShot(soundPlay.clip, .8f);
                diveSound = false;
            }

            //Moves bird to the middle of the screen
            target = Quaternion.Euler(0, 0, 44);
            transform.rotation = Quaternion.Slerp(transform.rotation, target, 1 );
            transform.position = Vector2.MoveTowards(new Vector2(transform.position.x, transform.position.y), updatedPosition, speed * Time.deltaTime);
            if (updatedPosition == transform.position)
                mid = true;
        }

        //Initiates when the bird reaches the middle of the screen, once it does, it moves the bird back off the screen
        if(mid)
        {
            StartCoroutine("midR");
            target = Quaternion.Euler(0, 0, -37.8f);

            //Rotates bird
            transform.rotation = Quaternion.Slerp(transform.rotation, target, Time.deltaTime * 25);
            transform.position = Vector2.MoveTowards(new Vector2(transform.position.x, transform.position.y), updatedPosition, speed * Time.deltaTime);
        }
    }

    IEnumerator midR() //Has the bird wait before it exits the water
    {
        Debug.Log("Co Routine start");
        yield return new WaitForSeconds(.2f); //waits up to 5 seconds
        updatedPosition = new Vector2(transform.position.x - 2, 8f);
        Debug.Log("Co Routine end");

    }

    IEnumerator moving() //Has the bird wait before it enters stage
    {
        Debug.Log("Co Routine start");
        yield return new WaitForSeconds(1f); //waits up to 5 seconds
        track = false;
        Debug.Log("Co Routine end");

    }
}
