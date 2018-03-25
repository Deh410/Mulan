import { Component } from '@angular/core';
import { NavController } from 'ionic-angular';

//Local importing of plugins set in app module
import { SpeechRecognition } from '@ionic-native/speech-recognition';
import { ChangeDetectorRef } from '@angular/core';
import { TextToSpeech } from '@ionic-native/text-to-speech';

//Importing HTTPClient to POST and GET requests
import { HttpClient } from '@angular/common/http';

@Component({
  selector: 'page-home',
  templateUrl: 'home.html'
})

export class HomePage {

  keyAPI = 'oUpd8bXsHMgNnT2n';
  checkIfAvailable = false;

  matches: string[];
  isRecording = false;

  correctedSentence = '';
  receivedObject;

  constructor(public navCtrl: NavController, private httpClient: HttpClient, 
  	private speechRecognition: SpeechRecognition, private changeDetector: ChangeDetectorRef,
  	private txtToSpeech: TextToSpeech) {

  }

  // Methods to record audio
  public startRecording(){
  	// Get user permission to access microfone
  	this.speechRecognition.hasPermission().
  	then((hasPermission: boolean) => {
  		if(!hasPermission){
  			this.speechRecognition.requestPermission();
  		}
  	});

  	// Start to record audio
  	let options = {
  		language: 'en-US'
  	}
  	this.speechRecognition.startListening(options).subscribe(matches => {
  		this.matches = matches;
  		this.changeDetector.detectChanges();
  		this.isRecording = true;
  		this.correctedSentence = this.matches[0];
  		this.correctedSentence = this.correctedSentence.replace(this.correctedSentence.charAt(0), this.correctedSentence.charAt(0).toUpperCase());
  	});

  	this.isRecording = false;
  }

  // Reproduce audio already stored in correctedSentece
  public translateTextToAudio(){

  	if(this.checkIfAvailable){
  	  this.txtToSpeech.speak({text: this.correctedSentence, locale: 'en-US', rate:  0.7}).
  		then(() => console.log('It is working properly'))
  		.catch((reason: any) => console.log(reason));	
  	}
  	else{
  		console.log("It does not have a valid value")
  	}

  }

 // Make a call to WebAPI, https://api.textgears.com/
  public requestAPI(){

  	if(this.matches != null){
	  	var url = 'https://api.textgears.com/check.php?text=' + this.correctedSentence + '&&key=' + this.keyAPI;

	  	this.httpClient.get(url)
	  		.subscribe(data => {
	  			this.receivedObject = data;
	  			
	  	});  
	  	this.correctSentence();		
  	}
  }

 // Correct sentence with regex interporlation
  public correctSentence(){

  	if(this.receivedObject != null){
  		for(var i = 0; i < this.receivedObject.errors.length; i++){
  			var regex = this.receivedObject.errors[i].bad;
  			var recommendation = this.receivedObject.errors[i].better[0];
  			console.log(this.correctedSentence);
  			console.log(recommendation, regex);
  			this.correctedSentence = this.correctedSentence.replace(regex, recommendation);
  		}
  		this.checkIfAvailable = true;
  	}
  }

}
