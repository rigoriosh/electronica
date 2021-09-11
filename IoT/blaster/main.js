if (!navigator.bluetooth) {
    alert('Sorry, your browser doesn\'t support Bluetooth API');
  }
  
  const MY_BLUETOOTH_NAME = 'HUAWEI Y9 Prime 2019rrh';
  const SEND_SERVICE = 0xFFE0;
  const SEND_SERVICE_CHARACTERISTIC = 0xFFE1;
  
  const controlButtonsListElements = document.querySelectorAll('.control-buttons > li');
  const connectButton = document.getElementById('connectButton');
  const disconnectButton = document.getElementById('disconnectButton');
  const lightOffButton = document.getElementById('lightOff');
  const toggleRedLightButton = document.getElementById('toggleRedLight');
  const toggleBlueLightButton = document.getElementById('toggleBlueLight');
  const toggleGreenLightButton = document.getElementById('toggleGreenLight');
  const runBlinkLightButton = document.getElementById('runBlinkLight');
  
  let toggleLigthCharacteristic;
  let myDevice;
  
  connectButton.addEventListener('pointerup', connectButtonPointerUpHandler);
  
  function connectButtonPointerUpHandler() {
    let chosenHeartRateService = null;

    navigator.bluetooth.requestDevice({
    filters: [{
        services: ['heart_rate'],
    }]
    }).then(device => device.gatt.connect())
    .then(server => server.getPrimaryService('heart_rate'))
    .then(service => {
    chosenHeartRateService = service;
    return Promise.all([
        service.getCharacteristic('body_sensor_location')
        .then(handleBodySensorLocationCharacteristic),
        service.getCharacteristic('heart_rate_measurement')
        .then(handleHeartRateMeasurementCharacteristic),
    ]);
    });
  }
  
  function lightOffButtonClickHandler() {
    return toggleLigthCharacteristic.writeValue(Uint8Array.of(0));
  }
  
  function toggleLightButtonClickHandler(event) {
    const code = Number(event.target.dataset.code);
  
    if (code === 1) {
      toggleLigthCharacteristic.writeValue(Uint8Array.of(code));
  
      return;
    }
  
    toggleLigthCharacteristic.readValue()
      .then(currentCode => {
        const convertedCode = currentCode.getUint8(0);
  
        toggleLigthCharacteristic.writeValue(Uint8Array.of(convertedCode === code ? 0 : code));
      });
  }
  
  function toggleButtonsVisible() {
    Array.prototype.forEach.call(controlButtonsListElements, listElement => {
      listElement.classList.toggle('visible');
    });
  }
  
  function disconnectButtonClickHandler() {
    lightOffButtonClickHandler()
      .then( () => {
        myDevice.gatt.disconnect();
  
        toggleItemsEventListeners('removeEventListener');
        toggleButtonsVisible();
  
        toggleLigthCharacteristic = undefined;
        myDevice = undefined;
      });
  }
  
  function toggleItemsEventListeners(action) {
    disconnectButton[action]('click', disconnectButtonClickHandler);
    lightOffButton[action]('click', lightOffButtonClickHandler);
    runBlinkLightButton[action]('click', toggleLightButtonClickHandler);
    toggleGreenLightButton[action]('click', toggleLightButtonClickHandler);
    toggleRedLightButton[action]('click', toggleLightButtonClickHandler);
    toggleBlueLightButton[action]('click', toggleLightButtonClickHandler);
  }

  function handleBodySensorLocationCharacteristic(characteristic) {
    if (characteristic === null) {
      console.log("Unknown sensor location.");
      return Promise.resolve();
    }
    return characteristic.readValue()
    .then(sensorLocationData => {
      const sensorLocation = sensorLocationData.getUint8(0);
      switch (sensorLocation) {
        case 0: return 'Other';
        case 1: return 'Chest';
        case 2: return 'Wrist';
        case 3: return 'Finger';
        case 4: return 'Hand';
        case 5: return 'Ear Lobe';
        case 6: return 'Foot';
        default: return 'Unknown';
      }
    }).then(location => console.log(location));
  }
  
  function handleHeartRateMeasurementCharacteristic(characteristic) {
    return characteristic.startNotifications()
    .then(char => {
      characteristic.addEventListener('characteristicvaluechanged',
                                      onHeartRateChanged);
    });
  }
  
  function onHeartRateChanged(event) {
    const characteristic = event.target;
    console.log(parseHeartRate(characteristic.value));
  }