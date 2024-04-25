function showNotification() {
    // Create a notification element
    const notification = document.createElement('div');
    notification.classList.add('notification');
    notification.textContent = 'This is a notification!';

    // Append the notification to the document body
    document.body.appendChild(notification);

    // Display the notification
    notification.style.display = 'block';

    // Automatically hide the notification after a delay (e.g., 3 seconds)
    setTimeout(() => {
        notification.style.display = 'none';
        // Remove the notification element from the DOM after hiding (optional)
        document.body.removeChild(notification);
    }, 3000); // Adjust the delay (in milliseconds) as needed
}


