using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Ball : MonoBehaviour {

    private Rigidbody2D rb2d;
    public bool onGround;
    public GameObject ball;
    public bool grabbed = false;
    /*
    void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.gameObject.tag == "Mouth" && onGround)
        {
            Debug.Log("Haha we touch willy");
            grabbed = true;
            ball.transform.position = collision.gameObject.transform.position;
        }
    }
    */
// Use this for initialization
    void Start () {
        rb2d = GetComponent<Rigidbody2D>();

    }
	
	// Update is called once per frame
	void Update () {
        IsGrounded();
        if(grabbed)
        {

        }
	}

    void IsGrounded()
    {
        if (rb2d.velocity.y == 0)
            onGround = true;
        else
            onGround = false;
    }
}
