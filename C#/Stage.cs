using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Stage : MonoBehaviour
{
    public PlatformGenerator camera;
    public bool stop = false;
    public float speed;
    // Use this for initialization
    void Start()
    {
        camera = GameObject.FindGameObjectWithTag("MainCamera").GetComponent<PlatformGenerator>();
    }

    // Update is called once per frame
    void Update()
    {
        if (stop)
        {
            transform.position = new Vector3(camera.transform.position.x, transform.position.y, transform.position.z);
        }
    }


}