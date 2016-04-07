<div class="chapsection">
<p>
<span class="caplead">“Send, send, send!</span>” Danny commanded. He watched a laptop over Moshen’s shoulder, squinting through the glare of the sunlight from the bohemian coffee shop’s windows.
</p>
<p>
Moshen flicked the touchpad. “Done! And now… we wait!”
</p>
<p>
Danny’s team sat at a cluster of tables at the B&amp;O Espresso, between walls lined with brass clocks and framed vintage posters. The B&amp;O made an ideal base &mdash; it had power outlets, free Wi-Fi access, and a menu of quadruple-shot chocolate lattes. Danny was already caffeinated to the point of nausea.
</p>
<p>
“What’d I miss?” asked Jason as he returned to the table.
</p>
<p>
“We’ve gone phishing!” said Moshen.
</p>
<p>
“We’re trying to figure out Tungsten’s IP address,” Danny clarified.
</p>
<p>
“Is that something you can get from their website?” Jason asked.
</p>
<p>
Danny shook his head. “Their website isn’t served from their office. They use Rackspace as a hosting solution. If we trace the route from here to their website, we won’t find their office IP address; we’ll just find their third-party web service provider.”
</p>
<p>
“But you <em>can</em> see their website, right?” asked Jason. “I always thought that’s the first thing hackers go for.”
</p>
<p>
“Their website has nothing to hack,” Danny answered. “They have a very simple, primitive web page. You can’t even use it for buying anything. If they had a big, complicated modern site with shopping carts and user comment sections, it’d be a different story. But as it stands, it’s only a bunch of sales pitches, and some phone numbers and email addresses.”
</p>
<p>
“I see,” Jason said. “Those all go to their receptionist, by the way. I’ve already checked out Tungsten’s public contact info.”
</p>
<p>
Moshen asked, “All of Tungsten’s emails go to the same person?”
</p>
<p>
Jason nodded. “Christina Giordano. Their all-purpose office admin.”
</p>
<p>
“Does she like spam?” asked Moshen. “I just sent her some hot, juicy junk mail.”
</p>
<p>
Jason cocked an eyebrow.
</p>
<p>
Danny explained, “About half an hour ago, Moshen and I hopped on GoDaddy and registered a website. We called it ‘Prismatic Creations’, made it look like a web design company. Then, we sent a few fake business solicitations to Tungsten. At the top of these emails, we added an image.”
</p>
<p>
“So what?” asked Jason.
</p>
<p>
“You ever get an email with pictures in it? And your browser warns you, ‘Click here to see the images in this message.’? Well, those images aren’t actually part of the email itself. What the email contains are <em>references</em> to images somewhere else on the Internet. The image at the top of our junkmail comes from the website we just built. And Moshen’s on the administrative back end right now, watching connections come in.”
</p>
<p>
“So… when the office admin opens that email… her computer will automatically connect to your new website?”
</p>
<p>
“Right,” said Danny. “And her computer is at her desk, so the IP address that she’s connecting from will be Tungsten’s corporate headquarters. Now, mind you, she could be using a really good spam filter, which would block the messages. Or she might delete them without opening. So this isn’t guaranteed to work…”
</p>
<p>
Moshen, his eyes devouring his laptop screen, shot both thumbs up. “It just did!”
</p>
<p>
Danny leaned over Moshen’s shoulder. The screen displayed:
</p>

<pre class="computer">
68.178.232.100 - - [20/Jul/2011:01:46:47 +0000] "GET /imag
es/logo.gif?tracker=73567354756 HTTP/1.1" 200 1537 "-" "Mo
zilla/5.0 (Windows NT 6.1; WOW64; rv:24.0) Gecko/20100101 
Thunderbird/3.0.1"
</pre>

<p>
“She’s using Mozilla Thunderbird mail reader on Windows 7,” Danny said. “Moshen, go cruise newsgroups and hacker forums, try to find exploits. I’ll check out Thunderbird’s source code and look for weaknesses. Mike, fire up Nessus and start probing their firewall.”
</p>
<p>
Jason tried to keep up. “Is there anything I could be doing?” he asked.
</p>
<p>
“Yes,” said Danny. “Get us more lattes.”
</p>
<p>
</div>

<div class="chapsection">
<p>
<span class="caplead">“Nothing’s getting through!”</span> Moshen hissed. He hunched over his laptop, fingers banging the keyboard. “The packets are just disappearing!”
</p>
<p>
“Did Tungsten go offline?” asked Danny, standing over his shoulder. “Or did we?”
</p>
<p>
“Neither. I can still reach Tungsten if I bounce through a proxy server,” said Moshen. “It’s like something started blocking <em>our</em> connection &mdash; <em>specifically</em> us here at the coffee shop. It doesn’t make any sense…”
</p>
<p>
Mike saw their agitation. “What are you guys doing?”
</p>
<p>
“We found an app called SSHatter on a hacker forum,” Danny answered. “We’re trying to use it to crack our way in.”
</p>
<p>
Mike raised an eyebrow. “You own a botnet?”
</p>
<p>
“No, we just ran it on Moshen’s laptop here.”
</p>
<p>
Mike winced. “That’s… Um… Not how it’s designed to work…”
</p>
<p>
Jason returned with several cups of coffee. “Hey, guys. Is everything alright?”
</p>
<p>
Danny replied, “Have you ever heard of SSH?” Jason shook his head. “It stands for ‘Secure Shell’. It’s a remote login program. It’s a very common tool &mdash; system administrators use it to access their own systems from home, for example. Most corporate servers have it installed.”
</p>
<p>
Jason nodded. “Like a back door for authorized personnel only, right?”
</p>
<p>
“A <em>heavily guarded</em> back door,” Mike emphasized. “The connection is encrypted. It’s useless without login credentials.”
</p>
<p>
“Which we were trying to figure out…” said Danny.
</p>
<p>
Mike scoffed, “Yeah, using SSHatter, on <em>one</em> host.”
</p>
<p>
“In English?” Jason insisted.
</p>
<p>
Danny answered, “SSHatter is a program that performs something called a dictionary attack. It has a database of common usernames and passwords. We rigged SSHatter to connect to Tungsten over and over again, as fast as it can, using common logins until we stumble across one that works.”
</p>
<p>
“Except that’s not how it’s supposed to be used,” Mike added flatly. “The number of possible username and password combinations is astronomical. SSHatter is designed for distributed operation &mdash; you’re supposed to divide up the task across a botnet with thousands of zombie hosts. And even then, the process can take days, without any guarantee of success. If you try to run it on just <em>one</em> machine, you…”
</p>
<p>
“Yes, it could theoretically take <em>years</em>, I know,” Danny interrupted. “Look, I realized that the probability of success was low. Fine. But I figured it’s worth at least trying. It can’t hurt, right?”
</p>
<p>
Mike grimaced. “It most certainly <em>can</em> hurt. You just tripped their DenyHosts IPS.”
</p>
<p>
Danny’s eyes flew open. He gasped as he realized that Mike was right.
</p>
<p>
Jason prodded, “Their what? ‘DenyHosts IPS’?”
</p>
<p>
Danny mumbled through his palms, “Their Intrusion Prevention System.”
</p>
<p>
“It’s another program that corporate servers use alongside SSH,” Mike explained. “A watchdog, basically. It monitors incoming network connections to detect potential hacker activity. And you know what it considers a giant red flag? When it sees the same machine connecting over and over very fast, trying lots of different logins.”
</p>
<p>
Danny looked down. “So when I ran SSHatter on Moshen’s computer…” 
</p>
<p>
Mike finished for him, “You set off their alarm, and now your source IP address is blocked, so none of your connections are getting through. Right?”
</p>
<p>
Danny said nothing.
</p>
<p>
Mike looked at him sidelong. “Danny, you… Um… You couldn’t seriously think it would be that easy, right? That you could just crack your way through SSH with some app you download from a website? If an SSH-cracking tool like that existed, do you have any idea what that would do to the entire Internet? Hell, system administrators have taken entire companies offline because of <em>rumors</em> about stuff like that! Don’t take this the wrong way, Danny, but… Are you sure you know what you’re doing?”
</p>
<p>
Staring at the floor, his chest tight, Danny squeezed out, “I have everything perfectly under control.”
</p>
<p>
After a few deep breaths, he raised his head and looked blankly around the coffee shop. The apron-clad waitstaff scurried about the tables and counters. He watched them for several silent seconds.
</p>
<p>
“Mike… Tell me that part again about how some system administrators took their companies offline because of rumors of an SSH-cracking tool?”
</p>
<p>
“Not much to tell,” Mike replied. “A couple years ago, somebody hacked a website called ImageShack. A hacker group called ‘anti-sec’ publicly announced that they were responsible for the break-in, and that they used a brand-new all-powerful hacker tool to do it. System administrators all over the world freaked out. They completely disabled SSH on their networks &mdash; they figured it’s better to not let <em>anybody</em> connect, not even legitimate users, than to give a hacker a route of entry.”
</p>
<p>
“That sounds like more than just a rumor,” said Danny. “That’s a serious threat.”
</p>
<p>
“It would have been, if it was real,” continued Mike. “But it turned out that the hacker group lied. There was no such tool. It was all a giant hoax. Just a bunch of punks trying to make themselves look powerful, freak people out. Which, granted, it did. But so what? All it proves is how crazy everything would be <em>if</em> there was a vulnerability in SSH. But there isn’t.”
</p>
<p>
Danny thought for a moment. “Not even through its own system administrators?”
</p>
<p>
Mike shook his head. “I don’t follow.”
</p>
<p>
Danny paced as he talked. “These anti-sec guys <em>succeeded</em> in taking a bunch of companies offline &mdash; not by exploiting a flaw in the <em>machines</em>, but by tricking the sysadmins who run them. Hacking is making a system do something that it isn’t supposed to do. That system includes people. It’s built and maintained by people. Tungsten’s IT staff itself is a system component. Let’s look for vulnerabilities in it.” He turned toward Jason, who was fiddling with his phone. “How big is Tungsten’s Information Technology department?”
</p>
<p>
“Just one guy,” Jason answered. “They have a couple older technicians around to maintain the equipment, but they’re not in charge of the corporate network. Their system administrator is some hipster kid. I don’t know his name.”
</p>
<p>
“I bet LinkedIn does,” said Danny. 
</p>
<p>
Moshen tapped away on his laptop. “Tungsten Medical Technologies… Network administrator… Got it! Roger Tanner. Jason, is this him?” Moshen turned his laptop around to show the screen. It displayed a Facebook profile page. The photo showed a young man with dark spiked hair and narrow black-framed glasses. Jason nodded.
</p>
<p>
Danny studied the screen. “His username is ‘rot13er’. He probably uses that same handle everywhere. Let’s see what this guy’s all about. Search around the web. Check message forums, social networks, anything.”
</p>
<p>
After several minutes, Mike piped up. “Danny. You were right. I think I found something. It’s an online tech-support forum for a company called OmniVision. They make security cameras. Check this out…”
</p>

<div class="computer email">
User: rot13er (Member, active 1 day)<br/>
Do you have a software upgrade for the OmniVision Sightbulb-1200 PTZ to give it WPA support? My company has about 30 of these cameras, installed ten years ago. We have a few wireless access points to connect them to the corporate LAN, but I have to run these APs with WEP because the cameras don’t speak WPA.<br/>
---<br/>
<br/>
User: David Swan (OmniVision Support Engineer)<br/>
I'm sorry to inform you that we discontinued support for the Sightbulb series about four years ago. I advise replacing with our Clarity line. I'd be happy to pass you along to our sales department.<br/>
---<br/>
<br/>
User: rot13er<br/>
My company's not paying for 30 new cameras. All I want is a firmware patch.<br/>
---<br/>
<br/>
User: David Swan<br/>
The Sightbulbs were manufactured before WEP's weaknesses were discovered. Unfortunately, it was technically infeasible to migrate the Sightbulb-1200 to WPA.<br/>
---<br/>
<br/>
User: rot13er<br/>
Are you serious? WEP is worthless. I might as well not even be running encryption at all. Thanks for nothing.<br/>
</div>

<p>
Danny smirked as he read the exchange. “Nice find, Mike! Gentlemen, let’s reconvene tonight after dark, and head over to Tungsten HQ. And savor the irony: we’ll be penetrating their network through their security cameras.”
</p>
</div>
