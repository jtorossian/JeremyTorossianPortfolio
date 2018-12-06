using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class obstical : MonoBehaviour {

    public Spawner spawnCheck;
    //Destroys stage when collision with despawner is made
    void OnTriggerEnter2D(Collider2D collision)
    {
     
        if (collision.gameObject.tag == "Despawn")
        {
            Destroy(spawnCheck.cloneDestory);
        }
        
        //Tells spawner to spawn next stage
        if (collision.gameObject.tag == "SpawnZone")
        {
            spawnCheck.spawn = true;
        }
    }
        // Use this for initialization
    void Start () {
         spawnCheck = GameObject.FindGameObjectWithTag("Spawner").GetComponent<Spawner>();
    }
	
	// Update is called once per frame
	void Update () {
		
	}
}
