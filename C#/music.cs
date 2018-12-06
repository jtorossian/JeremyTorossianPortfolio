using System.Collections;
using System.Collections.Generic;
using UnityEngine;


public class music : MonoBehaviour {

	// Use this for initialization
    //Keeps music throughout the entire game
	void Awake () {
        GameObject[] musicObj = GameObject.FindGameObjectsWithTag("Music");
        if (musicObj.Length > 1)
            Destroy(this.gameObject);

        DontDestroyOnLoad(this.gameObject);
	}


}
