using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Fish : MonoBehaviour
{
    public bool grabbed = false;
    RaycastHit2D hit;
    public float distance = 2f;
    public Transform holdPoint;
    // Use this for initialization

    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKeyDown("space"))
        {
            if (!grabbed)
            {
                hit = Physics2D.Raycast(transform.position, Vector2.right * transform.localScale.x, distance);

               
                if (hit.collider!=null)
                {
                    Debug.Log("We Hit Something");
                    grabbed = true;
                }

            }
        }

        if (grabbed)
            hit.collider.gameObject.transform.position = holdPoint.position;



    }

    void OnDrawGizmos()
    {
        Gizmos.color = Color.green;

        Gizmos.DrawLine(transform.position, transform.position + Vector3.right * transform.localScale.x * distance);
    }
     
    }
