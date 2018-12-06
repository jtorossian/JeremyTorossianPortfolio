using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Zone2 : MonoBehaviour {
    public PlayerController fish;
    public Animator animator;
    public AudioClip mouth;

    //Once the fish enters this zone, it changes the shark pose
    void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.gameObject.tag == "Fish")
        {
            animator.SetBool("Stage2", true);
        }
    }

    void OnTriggerStay2D(Collider2D collision)
    {
        if (collision.gameObject.tag == "Fish")
        {
            animator.SetBool("Stage2", true);
        }
    }


    void OnTriggerExit2D(Collider2D collision)
    {
        if (collision.gameObject.tag == "Fish")
        {
            animator.SetBool("Stage2", false);
        }
    }

    // Use this for initialization
    void Start()
    {
        fish = GameObject.FindGameObjectWithTag("Fish").GetComponent<PlayerController>();
    }

    // Update is called once per frame
    void Update()
    {

    }
}
