var firebase = require('firebase')
// datos de firebase
var config = {

  apiKey: "AIzaSyBh2i1CCIaz6uY6uz4EVao69HiskvxrSZk",
  authDomain: "monitor-9a16f.firebaseapp.com",
  databaseURL: "https://monitor-9a16f-default-rtdb.firebaseio.com",
  projectId: "monitor-9a16f",
  storageBucket: "monitor-9a16f.appspot.com",
  messagingSenderId: "864280604013",
  appId: "1:864280604013:web:080f367dffe33953edfe64",
  measurementId: "G-23M3TSBJ52"
};

const fire = firebase.initializeApp(config);
module.exports = fire;
