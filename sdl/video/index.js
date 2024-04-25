document.getElementById("videoForm").addEventListener('submit', function(event) {
    event.preventDefault();
    
    const videoInput = document.getElementById("videoInput");
    const videoContainer = document.getElementById("videoContainer");
   
    if (!videoInput) {
        console.error("Video input element not found.");
        return;
    }

    if (videoInput.files.length === 0) {
        alert("Please select a video.");
        return;
    }
    
    const videoFile = videoInput.files[0];

    if (!videoFile.type.startsWith('video/')) {
        alert("Please upload a valid video file.");
        return;
    }

    const videoURL = URL.createObjectURL(videoFile);

    // Display the uploaded video
    const videoElement = document.createElement('video');
    videoElement.src = videoURL;
    videoElement.controls = true;

    // Clear previous video (if any) and append the new video element
    videoContainer.innerHTML = '';
    videoContainer.appendChild(videoElement);
});
