using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Swordfish : MonoBehaviour {
    public Despawner end;
    public SwordFishSpawner Spawn;
    public Vector3 startPosition;
    private Vector3 updatedPosition;
    public float speed;
    public GameObject indicator;
    private GameObject clone;
    public GameObject cloneDestory;
    public PlatformGenerator camera;
    public AudioClip[] swoosh;
    public AudioClip[] indicatorS;
    public AudioSource soundPlay;
    public bool swooshSound;
    public bool indicatorSound;
    private bool track;
    private bool Ispawn;
    private bool start;
    void OnTriggerEnter2D(Collider2D collision)
    {
        //Destroys swordfish when collision is made with despawners
        if (collision.gameObject.tag == "SwordfishDespawn")
        {
            Debug.Log("We Made it boys");
            Spawn.spawn = true;
            Destroy(gameObject);
        }

    }
    // Use this for initialization
    void Start () {
        end = GameObject.FindGameObjectWithTag("SwordfishDespawn").GetComponent<Despawner>();
        Spawn = GameObject.FindGameObjectWithTag("FishSpawn").GetComponent<SwordFishSpawner>();
        transform.position = new Vector3(transform.position.x, Random.Range(-4f, 4f), 0);
        camera = GameObject.FindGameObjectWithTag("MainCamera").GetComponent<PlatformGenerator>();
        Ispawn = true;
        start = false;
        track = true;
        indicatorSound = true;
        swooshSound = true;
    }
	
	// Update is called once per frame
	void Update () {

        if (Ispawn)
        {
            if (indicatorSound)
            {
                soundPlay.clip = indicatorS[Random.Range(0, 5)];
                soundPlay.Play();
                indicatorSound = false;
            }
            clone = Instantiate(indicator, new Vector3(transform.position.x, transform.position.y, transform.position.z), Quaternion.Euler(0, 0, 90), transform.parent);
            clone.transform.localScale = new Vector3(.3f, .3f, 1);
            Ispawn = false;
        }

        if (track)
        {
            transform.position = new Vector3(camera.transform.position.x + 14, transform.position.y, transform.position.z);
            clone.transform.position = new Vector3(camera.transform.position.x + 8, transform.position.y, transform.position.z);
            StartCoroutine("moving");
        }

        else if (!track)
        {
            if (swooshSound)
            {
                soundPlay.clip = swoosh[Random.Range(0, 5)];
                soundPlay.Play();
                swooshSound = false;
            }
            Destroy(clone);
            updatedPosition = new Vector2(end.transform.position.x, transform.position.y);
            transform.position = Vector2.MoveTowards(new Vector2(transform.position.x, transform.position.y), updatedPosition, speed * Time.deltaTime);
        }
    }

    IEnumerator moving()
    {
        Debug.Log("Co Routine start");
        yield return new WaitForSeconds(.75f); //waits up to 5 seconds
        track = false;
        Debug.Log("Co Routine end");

    }
}
