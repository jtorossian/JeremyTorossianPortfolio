using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;


public class deathmenu : MonoBehaviour {
    public WorldScript world;
    public Text finalDistance;
    // Use this for initialization

    void Start () {
        gameObject.SetActive(false);
        world = GameObject.FindGameObjectWithTag("world").GetComponent<WorldScript>();
    }
	
	// Update is called once per frame
	void Update () {
        //Gives player their final score
        finalDistance.text = world.distance.ToString() + "km";

    }
}
