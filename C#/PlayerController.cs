using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : MonoBehaviour
{

    public float speed;             //Floating point variable to store the player's movement speed.
    public float accelertaion;      //Every second, the speed will increase by this much
    public float maxspeed;          //Max speed the fish can go 
    public float minspeed;          //Minimum speed the fish can go
    public float rotationcheck;     //Keeps the fish from over rotating
    private Rigidbody2D rb2d;       //Store a reference to the Rigidbody2D component required to use 2D Physics.
    public AudioClip flip;
    public AudioSource soundPlay;

    bool facingRight = true;        //Keeps track if fish is facing right
    bool goingUp = true;            //Keeps track if the fish is going up


    void OnCollisionEnter2D(Collision2D collision)
    {
        if (collision.gameObject.tag == "Ground")
        {
            minspeed = 3;
            speed = minspeed;
        }
    }
    // Use this for initialization
    void Start()
    {
        //Get and store a reference to the Rigidbody2D component so that we can access it.
        rb2d = GetComponent<Rigidbody2D>();
        speed = maxspeed;
        accelertaion = 10;

    }


    void FixedUpdate()
    {
        //Store the current horizontal input in the float moveHorizontal.
        float moveHorizontal = Input.GetAxis("Horizontal"); 

        float moveVertical = Input.GetAxis("Vertical");

        
        speed += Time.deltaTime * accelertaion; //Calculates the speed of the fish. 
        
        //Prevents the speed from going past the max speed or under the min speed
        if (speed > maxspeed) 
            speed = maxspeed;

        if (speed < minspeed)
            speed = minspeed;

        //Keeps the fish from over rotating
        if (rotationcheck > 0)
            rotationcheck -= Time.deltaTime;
        else if (rotationcheck < 0)
            rotationcheck += Time.deltaTime;

        //Pushes the fish horizontally and vertically
        rb2d.AddRelativeForce(Vector2.up * moveVertical * speed);
        rb2d.AddRelativeForce(Vector2.right * moveHorizontal * speed);
        rb2d.MoveRotation(rotationcheck);


        //If the player is moving right and they are not facing right, calls the flipH function.
        if (moveHorizontal > 0 && !facingRight)
            flipH();
        //If the player is moving left and they are facing right, calls the flipH function.
        else if (moveHorizontal < 0 && facingRight)
            flipH();

        //If the player is moving up and their last movement was moving down, calls the flipV function.
        if (moveVertical < 0 && !goingUp)
            flipV();
        //If the player is moving down and their last movement was moving up, calls the flipV function.
        else if (moveVertical > 0 && goingUp)
            flipV();
   

    }


    void flipH()
    {
        soundPlay.clip = flip;
        soundPlay.Play();
        facingRight = !facingRight; //Sets facingRight to whatever it currently isn't
        speed -= speed / 2; // Halves the speed
        //Flips the sprite
        Vector3 theScale = transform.localScale;
        theScale.x *= -1;
        transform.localScale = theScale;
    }

    void flipV()
    {
        goingUp = !goingUp; //Sets goingUp to whatever it currently isn't
        speed -= speed / 2; // Halves the speed
    }
}