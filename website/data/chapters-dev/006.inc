<div class="chapsection">
<p>
<span class="caplead">“Send, send, send!</span>” Danny said eagerly. He watched a laptop over Moshen’s shoulder, angling himself to avoid the glare from the sunlight streaming in from the bohemian coffee shop’s windows.
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
“Does she like spam?” asked Moshen. “I just sent her some hot, juicy junkmail.”
</p>
<p>
Jason cocked an eyebrow.
</p>
<p>
Danny explained, “About half an hour ago, Moshen and I hopped on GoDaddy.com and registered a website. We called it ‘Prismatic Creations’, and made it look like a web design company. Then, we sent a few fake business solicitations to Tungsten. The trick is that, at the top of these emails, we added an image.”
</p>
<p>
“So what?” asked Jason.
</p>
<p>
“You ever get an email with pictures in it?” Danny said. “And your browser gives you a little warning bar that says, ‘Click here to see the images in this message.’? Well, those images aren’t actually part of the email itself. What the email contains are <em>references</em> to images somewhere else on the Internet. The image at the top of our junkmail comes from this website that we just built. And Moshen’s on the administrative back end right now, watching connections come in.”
</p>
<p>
Jason’s brow furrowed. “So… when the office admin opens that email… her computer will automatically connect to your new website?”
</p>
<p>
“Right,” said Danny. “And her computer is at her desk, so the IP address that she’s connecting from will be Tungsten’s corporate headquarters.”
</p>
<p>
Satish, sitting near Mike a few feet away, chimed in. “You know the chances of this succeeding are slim to none, right? She’ll just delete the emails without opening them.”
</p>
<p>
Danny cocked his head. “Satish? Why so negative?”
</p>
<p>
“I’m just pointing out the obvious, Danny,” said Satish. “Remember, I’m a Microsoft SDET. I spend all day looking at people’s broken-ass code and writing reports to explain why it’s hopelessly flawed. I’m not being ‘negative’; I’m doing my job. And I’m telling you, if you think this email trick stands a chance of working…”
</p>
<p>
Moshen, with his eyes on his laptop screen, shot both thumbs excitedly up. “It just did!”
</p>
<p>
Danny stuck his head over Moshen’s shoulder. “Guys! Check this out!” The screen displayed:
</p>

<pre class="computer">
68.178.232.100 - - [20/Jul/2011:01:46:47 +0000] "GET /imag
es/logo.gif?tracker=73567354756 HTTP/1.1" 200 1537 "-" "Mo
zilla/5.0 (Windows; U; Windows NT 5.1; en-US; rv:1.8.1.21)
 Gecko/20090302 Thunderbird/3.0.0.21"
</pre>

<p>
“She’s using Mozilla Thunderbird mail reader on Windows XP,” Danny said.  “Moshen, go cruise newsgroups and hacker forums; try to find any exploits or full disclosures. Satish, Thunderbird is open source, right? Check out the source code and see if you can find any weaknesses. Mike, you and I will try cracking through the firewall. Fire up Nessus and start probing.”
</p>
<p>
The group sprang to action. They rearranged their chairs and started typing furiously on their laptops.
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
<span class="caplead">Danny nibbled on his nails</span>, his eyes affixed nervously to Mike’s screen.
</p>
<p>
“Nothing’s getting through!” growled Mike. His body hunched over his laptop, fingers banging on the keyboard. “The SYN packets are just disappearing!”
</p>
<p>
“Did Tungsten go offline?” asked Danny. “Or did we?”
</p>
<p>
“No and no,” said Mike. “I can still reach Tungsten if I bounce through my school’s servers. It’s like something suddenly started blocking <em>our</em> connection to Tungsten’s servers &mdash; <em>specifically</em> our connection here at the coffee shop. It doesn’t make any sense…”
</p>
<p>
Satish saw their agitation. “What are you guys doing?”
</p>
<p>
“We ran a port scan,” Danny explained, his attention still on Mike’s screen. “They’ve got port 23 open.”
</p>
<p>
Satish shrugged. “Yeah. The SSH port. So what?”
</p>
<p>
“So, we figured we’d crack our way through it,” Danny said.
</p>
<p>
“How?” Satish pressed.
</p>
<p>
“With SSHatter.”
</p>
<p>
Satish raised an eyebrow. “You own a botnet?”
</p>
<p>
Danny replied, “No, we just ran it on Mike’s laptop here.”
</p>
<p>
Satish paused for a few beats. “Please tell me you’re being sarcastic…”
</p>
<p>
“I suppose you have a better idea?” Danny replied.
</p>
<p>
“It’s hard to think of a <em>worse</em> idea,” Satish volleyed.
</p>
<p>
Jason, returning to the tables with several cups of coffee, interjected himself into the fray. “Hey. Guys. Is there a personnel conflict I should know about?”
</p>
<p>
Satish answered, “Yes, there is. Jason, where did you find this noob, and why did you think it’d be a good idea for him to be in charge?”
</p>
<p>
“Hey!” Danny barked. “What the hell, Satish? I’m standing right here!”
</p>
<p>
Jason said firmly, “What’s going on, guys?”
</p>
<p>
Danny turned to Jason. “Have you ever heard of SSH?” Jason shook his head. “It stands for ‘Secure Shell’. It’s a remote login program. It’s a very common tool &mdash; system administrators use it so they can access their own systems in case of emergency. Most corporate-level computers have it installed.”
</p>
<p>
Jason nodded. “Like a back door for authorized personnel only, right?”
</p>
<p>
“A <em>heavily guarded</em> back door,” Satish emphasized. “The connection is encrypted. It’s useless without login credentials.”
</p>
<p>
“Which we were in the middle of trying to figure out…” said Danny.
</p>
<p>
Satish scoffed, “Yeah, with SSHatter, on <em>one</em> host!”
</p>
<p>
“In English?” Jason insisted.
</p>
<p>
Danny answered, “SSHatter is a program that performs something called a dictionary attack. It has a huge database of common usernames and passwords. We rigged SSHatter to connect to Tungsten over and over again, as fast as it can, using different common logins until we stumble across one that works.”
</p>
<p>
“Which is a complete dumbass approach!” Satish added. “See, when a <em>real</em> hacker uses SSHatter, they do some preparation first. The number of different possible username and password combinations is astronomical, so they divide up the task across a botnet with thousands of zombie hosts. And even then, the process can take days, without any guarantee of success. If you try to run it on just <em>one</em> machine, you…”
</p>
<p>
“Yes, it could theoretically take <em>years</em>, I know,” Danny interrupted. “Look, I realized that the probability of success was low. Fine. But Mike and I figured it’s worth at least trying. It couldn’t hurt, right?”
</p>
<p>
Satish grimaced. “It most certainly <em>can</em> hurt! You just tripped their DenyHosts IPS, you clueless idiot!”
</p>
<p>
Danny’s eyes flew open. He gasped as he realized that Satish was right.
</p>
<p>
Jason prodded, “Their what? ‘DenyHosts IPS’?”
</p>
<p>
Danny, his face buried in his hands, mumbled through his palms, “Their Intrusion Prevention System.”
</p>
<p>
Satish said to Jason, “It’s another program that corporate servers use alongside SSH. It watches incoming network connections to detect potential hacker activity. And you know what it considers a giant red flag? When it sees the same machine connecting over and over very fast, trying lots of different logins.”
</p>
<p>
Danny looked down. “So when Mike and I tried to use SSHatter…” 
</p>
<p>
Satish finished for him, “You set off their alarm, and now your source IP address is blocked, so none of your connections are getting through. Right?”
</p>
<p>
Danny said nothing. 
</p>
<p>
Satish shook his head. “Did you dumb shits seriously think you could crack your way in through SSH with a cheap script-kiddie tool? If a tool like that existed, do you have any idea what that would do to the entire Internet? Hell, system administrators have taken entire companies offline because of <em>rumors</em> about a tool that could crack SSH like that! To think that <em>this</em> team of morons could pull off a…”
</p>
<p>
Jason intervened, “Satish, maybe dial the insults down a notch? This isn’t a Dungeons and Dragons campaign. We’re all trying to solve a real challenge here.”
</p>
<p>
Satish shot back to Jason, “You think I don’t know that? You think I don't know that this shit has real consequences? If anything gets traced back to us, we could all end up getting prosecuted. I’m here on a H1-B visa, and I refuse to get deported because of some cock-up on the part of this dimwit here who doesn’t know what the fuck he’s doing!”
</p>
<p>
Danny felt his throat seize with a jolt of anger. He shot Satish a steely glare. “I have everything perfectly under control. Do not question my technical expertise.”
</p>
<p>
Satish scoffed, “So far, you haven’t shown any for me to question.”
</p>
<p>
Danny forced himself to look away, and took a few deep breaths to calm down. His fingers slowly relaxed out from his tightly squeezed fists. He looked around the B&amp;O Espresso. The group’s quarrel had begun to cause a scene. As the coffee shop’s staff scurried about the tables and counters, they gave Danny and his hacker crew sidelong glances. “Satish,” he said with forced calmness. “Tell me that part again about how some system administrators took their companies offline because of rumors of an SSH-cracking tool?”
</p>
<p>
“Not much to tell,” said Satish. “A couple years ago, somebody hacked a website called ImageShack. A hacker group called ‘anti-sec’ publicly announced that they were responsible for the break-in, and that they had done it by using a brand-new hacker tool that worked by cracking SSH. System administrators all over the world saw this and freaked out. They completely disabled SSH on their networks &mdash; they figured it’s better to not let <em>anybody</em> connect, not even legitimate users, than to give a hacker a route of entry.”
</p>
<p>
“That sounds like more than just a rumor,” said Danny. “That’s a serious threat.”
</p>
<p>
“It would have been, if it was real,” said Satish. “But it turned out that the hacker group lied. There was no such SSH-cracking tool. It was all a giant hoax.”
</p>
<p>
“Did they have a motive?” asked Danny.
</p>
<p>
“Just to cause a panic,” said Satish. “Make themselves look powerful, freak people out. Which it did. But so what? All it proves is how crazy everything would be if there was a vulnerability in SSH. But there isn’t.”
</p>
<p>
Danny thought for a moment. “Not even through its own system administrators?” he said pensively.
</p>
<p>
Satish shook his head. “I don’t follow.”
</p>
<p>
Danny paced as he talked, his fingers fidgeting. “These anti-sec guys succeeded in taking a bunch of companies offline not by exploiting a flaw in the machines, but by tricking the sysadmins who run them. Hacking is making a system do something that it isn’t supposed to do. That system includes people. It’s built and maintained by people. Tungsten’s IT staff itself is a system component. Let’s look for vulnerabilities in it.” He turned toward Jason, who was fiddling on his cellphone. “How big is Tungsten’s Information Technology department?”
</p>
<p>
“Just one guy,” Jason answered. “They have a couple older technicians around to help maintain the medical equipment, but they’re not in charge of the corporate network. Their system administrator is some hipster kid. I don’t know his name.”
</p>
<p>
“I bet LinkedIn does,” said Danny. 
</p>
<p>
Moshen tapped away on his laptop. “Tungsten Medical Technologies… Network administrator… Got it! Roger Tanner.”
</p>
<p>
“Roger Tanner,” repeated Mike while working. “Jason, is this him?” Mike turned his laptop around to show Jason the screen. It displayed a Facebook profile page. The photo showed a young man with dark spiked hair and narrow black-framed glasses. Jason nodded.
</p>
<p>
Danny peeked at the screen over Mike’s shoulder. “His username is ‘rot13er’. He probably uses that same handle everywhere. Let’s see what this guy’s all about. Search around the web. Check message forums, social networks, anything.”
</p>
<p>
Mike and Moshen set to work alongside Danny. Satish sat silently nearby, eyeing the endeavor with grudging interest.
</p>
<p>
After several minutes, Mike piped up. “Danny! I found something! It’s an online tech-support forum for a company called OmniVision. They make security cameras. Check this out…”
</p>
<p>

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
<p>
</div>
