require 'net/smtp'

def send_email(sender_email, sender_password, recipient_email, subject, body)
  smtp_server = 'smtp.gmail.com'
  smtp_port = 587

  message = <<END_OF_MESSAGE
From: Your Name <#{sender_email}>
To: Recipient <#{recipient_email}>
Subject: #{subject}

#{body}
END_OF_MESSAGE

  begin
    Net::SMTP.start(smtp_server, smtp_port, 'localhost', sender_email, sender_password, :login) do |smtp|
      smtp.send_message(message, sender_email, recipient_email)
    end
    puts "Email sent successfully!"
  rescue => e
    puts "Error sending email: #{e.message}"
  end
end

# Input details for sending the email
sender_email = 'sahil.dhargave21@pccoepune.org'
sender_password = '121B10689'
recipient_email = 'sahildhargave5253@gmail.com'
subject = 'Sending email using Ruby'
body = 'This is a test email sent using Net::SMTP in Ruby.'

# Call the send_email method with provided details
send_email(sender_email, sender_password, recipient_email, subject, body)
