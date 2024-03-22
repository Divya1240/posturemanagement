document.addEventListener('DOMContentLoaded', function () {
    const registrationForm = document.getElementById('registration-form');
    registrationForm.addEventListener('submit', function (event) {
        event.preventDefault();
        const patientName = document.getElementById('patient-name').value;
        const patientAge = document.getElementById('patient-age').value;
        const parentName = document.getElementById('parent-name').value;
        // Add your logic for registering the patient here
        alert(`Patient ${patientName} (${patientAge} years old) registered successfully. Parent/Guardian: ${parentName}`);
        // Redirect to another page if needed
        window.location.href = 'index.html'; // Redirecting back to index page
    });
});
