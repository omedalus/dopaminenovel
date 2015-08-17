<div class="chapsection">
<p>
<span class="caplead">Once upon a time, there stood a mighty city</span> of alabaster towers and golden spires. Envious of its majesty, a warlord from Byzantium cast his covetous eye upon it. 
</p>
<p>
And so it came to pass that the city’s watchmen saw the dust of marching boots rise above the surrounding farmland. Temples and palaces trembled from the rumble of advancing footfall. Thousands of iron-helmed soldiers encircled the city. Trebuchets were erected upon hilltops, and battering rams hoisted to the gates. The Byzantine General called out a demand for unconditional surrender.
</p>
<p>
A city herald shouted to the invaders to go home and save themselves.
</p>
<p>
For, in truth, many times had this city known war, but never had it fallen. Its marble walls were strong, but the city’s true defenses rested in a unique weapon: a corps of elite spies. Armed solely with subterfuge, these cunning operatives crushed entire armies without firing a single arrow.
</p>
<p>
The spies’ methods were simple: when under siege, they disguised themselves as the attacker’s messengers and pages, and fed a General and his lieutenants false battlefield reports, causing the enemy to maneuver into traps. Sometimes, they bribed key lieutenants to betray their General, thus transforming a rear guard or flank defense into a scythe which, by surprise and position, reaped entire legions of the enemy’s own troops. Often, the spies would combine these techniques to devastating effect &mdash; convincing a General that a lieutenant had been bribed, thereby tricking him into executing loyal men; or sending two lieutenants falsified orders, telling each that the other was compromised and in need of dispatching, leaving the General to watch helplessly as two of his own companies slaughtered each other with no way to tell who, if anyone, had truly defected.
</p>
<p>
The Byzantine General knew the danger. He nonetheless vowed to attack at dawn, and withdrew to his tent.
</p>
<p>
There he sat, deep in thought, devising a battle plan. It had to operate over a network of untrustworthy pages. It had to account for possible treason, yet remain resilient against false alarms. And above all else, it had to end in victory.
</p>
<p>
Fortunately, the Byzantine General had downloaded a PDF of an article by Lamport, Shostak, and Pease in the July 1982 issue of <em>Transactions on Programming Languages and Systems</em> by the Association for Computing Machinery. He implemented a recursive distributed vote-driven decision algorithm that remained robust up to a traitor count of <em>t</em> &lt; <em>n</em>/3. The city was razed, its gold was plundered, and its name was erased from history. The end.
</p>

<hr/>

<p>
“Wait, <em>what</em>?” said Jason.
</p>
<p>
“Yeah, I know,” said Danny. “A recursive voting system sounds seriously inefficient, right? But you can distribute the recursion! The runtime is just O-of-n-log-n, which improves to linear if you use public-key encryption and a good certificate revocation scheme. Pretty cool, huh?”
</p>
<p>
Jason shook his head. “I think you lost me somewhere between ‘trebuchet’ and ‘algorithm’.”
</p>
<p>
“It’s an extended metaphor,” Danny explained. “We learn about it in graduate seminars on network security. The pageboys are network connections, the lieutenants are nodes, and the battle plan is a distributed computer program.”
</p>
<p>
“And the spies are hackers, right?” Jason said.
</p>
<p>
“Of course,” said Danny. “And the hackers can inject messages into your network, or even take control of some of your nodes.”
</p>
<p>
“And what exactly is the city supposed to be?” Jason asked.
</p>
<p>
“It’s… um… it’s… Actually, I have no idea.”
</p>
<p>
“What do you mean?” Jason said. “The city’s got to represent something.”
</p>
<p>
“The city’s not important,” said Danny. “The battle plan is. That’s the part with the math.”
</p>
<p>
Jason laughed at him. “The city’s the whole point of the invasion! A fat lot of good a battle plan does you if you don’t know what you’re fighting for.”
</p>
<p>
“I think you’re missing the point of the analogy.”
</p>
<p>
“I think the analogy misses the point of itself,” said Jason.
</p>
<p>
The two of them sat in Jason’s bullet-pocked Lincoln Navigator, parked behind a chain-link fence in a gravel-strewn lot along Seattle’s southward industrial expanse. Around them sprawled blocks of vast squat storage spaces known as “fulfillment houses”, the integral middlemen who ensured that every cardboard-boxed package ordered by customers of Amazon or Microsoft or Nordstrom would get to its delivery address. To the north loomed the immense steel container cranes of the Port of Seattle, each one an Erector-set structure standing thirty stories tall. This sector of the city was alive even at this time of night; the enormous metal arms of the container cranes swung over cargo ships, the BSNF railroad rumbled, and trucks docked in the fulfillment houses’ loading zones like bees at a hive. Underlying the Emerald City’s success as a hub of technology was simple geography &mdash; her location on the shores of the natural harbor of Elliott Bay. She was, first and foremost, a port city, and every night ten million consumer goods had to roll out by sunrise.
</p>
<p>
Danny sat in the passenger seat, looking at his cellphone and giggling. Moshen was sending him forwards of every email, keeping him in the loop. Danny had a front-row seat to the chaos that Mike, Moshen, and Satish were sowing at that very moment.
</p>

<div class="computer email">
From: Eugene &lt;eugene@pash.ly&gt;<br/>
Subject: Phone burned<br/>
Hey guys. Lost my phone. Sorry. Burn the number. 
</div>

<p>
That email had been real. Eugene had sent it about a half hour prior. It was delivered to a long list of recipients, many with Spanish names, many just initials, and a few with monikers like “4 Shizzy” or “Wheel Bone” or “Booty Fresh”.
</p>

<div class="computer email">
From: Eugene &lt;eugene@pash.ly&gt;<br/>
Subject: Phone NOT burned. WTF?<br/>

Guys, I DID NOT send that last email. My phone is fine. Who sent that? If it was one of you, you are in big trouble.
</div>

<p>
That had been the first of the forged emails, sent to the same distribution list as Eugene’s real one. 
</p>
<p>
“Why would you tell them that?” Jason had asked when the hacker crew sent it out.
</p>
<p>
“The trick to inducing a Byzantine failure mode is to get the nodes to trust messages that they shouldn’t, and to distrust messages that they should,” Danny explained. “Part of that involves casting doubt on the messages that are intended to maintain the cohesion of the message distribution system itself. In PKE, we’d call this a certificate reissue forgery.”
</p>
<p>
“But now they know there’s a hacker among them,” Jason had pointed out.
</p>
<p>
“Let them. Exposing that fact helps sow distrust among their ranks.”
</p>

<div class="computer email">
From: Eugene &lt;eugene@pash.ly&gt;<br/>
Subject: Phone burned. Burn this email address.<br/>
I lost my phone and some asshole who found it is pretending to be me. Burn my number AND ignore all other emails from this address. Its not a big deal, it was just a burner phone, nothing to worry, didn’t have annything important on it.. Will change my email password soon as I can. For now if you want to talk to me, talk to Leo.
</div>

<p>
“Of course, if he changes his password, that won’t matter to us at all,” Danny had said. “We’re not logging in as him in order to send these emails. What we’re doing is telling the mailserver at Mike’s college that these emails have already been sent. Then that college mailserver is passing along the message to all the mailservers of all his recipients. It’s as though we’re planting letters directly into a mailman’s truck.”
</p>

<div class="computer email">
From: Sergey &lt;sergey@pash.ly&gt;<br/>
Subject: Phone is fine but email is compromised<br/>
Guys, this is Sergey. Look, Eugene’s phone is fine, we have it right here. But obviously someone got into his email so burn his email.<br/>
-Sergey
</div>

<p>
Fake as hell. In retrospect, Danny considered that maybe they shouldn’t have used the word “compromised” when any normal human being outside the world of computer geekdom would say “hacked” or “stolen” or “broken into”. 
</p>

<div class="computer email">
From: Sergey &lt;sergey@pash.ly&gt;<br/>
Subject: I DID NOT SEND LAST EMAIL<br/>
This last emial saying Eugenes phone is fine, this was not me. Changing my password right now. DO NOT CALL EUGENE, DO NOT EMAIL EUGENE. BURN EUGENES CONTACT INFO RIGHT NOW. SOS.
</div>

<p>
Real.
</p>

<div class="computer email">
From: 4 Shizzy &lt;4shizzy@yahoo.com&gt;<br/>
Subject: I call you aint answering<br/>
Yo dog I trying to call u n figur out wtf goin on what gives? I’ve got a whole ki right here need to MOVE!
</div>

<p>
Real. Of course this 4 Shizzy person hadn’t gotten through to Eugene &mdash; the Russian’s SIM card was still in Danny’s pocket. However, this email had given the guys an idea…
</p>

<div class="computer email">
From: X D &lt;xavierdaniels1989@yahoo.com&gt;<br/>
Subject: Just talked to Eugene <br/>
Dunno what all the craziness is all about, I just taked to Eugene on the fone and he seems fine. He told me it’s Sergey’s phone that’s stolen.
</div>

<p>
Fake. This X D guy was just some random name from the Russians’ distribution list. The Russians responded with….
</p>

<div class="computer email">
From: Sergey &lt;sergey@pash.ly&gt;<br/>
Subject: Re: Just talked to Eugene<br/>
Has anyone else just called Eugene? Whoever you are talking to IS NOT EUGENE. EUGENE IS RIGT HERE WITH ME. DO NOT CALL EUGENE. BURN ALL EUGENE CONTACT INFO RIGHT NOW. THAT IS ORDER!!! If you want to talk to Eugene, call Leo or me.
</div>

<p>
Real. Danny’s team followed it with another spoof from X D.
</p>

<div class="computer email">
From: X D &lt;xavierdaniels1989@yahoo.com&gt;<br/>
Subject: RE: Just talked to Eugene <br/>
Sergey, what gives? I just talked to you on the phone like ten minutes ago and you gave a new phone num for Eugene. So do I burn both the old and the new number, or just the old and keep the new? I’m confused. Let me know what I shd do. 
</div>

<p>
Sergey’s real response came a few seconds later:
</p>

<div class="computer email">
From: Sergey &lt;sergey@pash.ly&gt;<br/>
Subject: RE: Just talked to Eugene <br/>
What do you mean?? You just talked to me on a phone? No we didn’t. 
</div>

<p>
The hacker crew chased it with a series of forged messages from Sergey’s minions.
</p>

<div class="computer email">
From: X D &lt;xavierdaniels1989@yahoo.com&gt;<br/>
Subject: RE: Just talked to Eugene <br/>
Yeah we did. We talked on the phone just a little while ago. Sergey, is everything ok?
</div>

<div class="computer email">
From: 4 Shizzy &lt;4shizzy@yahoo.com&gt;<br/>
Subject: RE: Just talked to Eugene <br/>
Yeah man. Just got off the phone with u 2, u sounded a little weird.
</div>

<div class="computer email">
From: Miguel &lt;mg323329@msn.com&gt;<br/>
Subject: RE: Just talked to Eugene <br/>
Sergey just call me on phone and tell me to make delivery to new address downtown. He sounded strange. I go check out the place, is right next to police station! Something about this is all wrong.
</div>

<p>
And in response, Sergey delivered his own coup de grâce: 
</p>

<div class="computer email">
From: Leo &lt;leonya@pash.ly&gt;<br/>
Subject: LOCKDOWN<br/>
This is Sergey. I using Leo email because Leo not having any problems, thanks God. I do not know what is going on. Somebody send out emails from my account, pretend to be me and gives strange orders. I change password, but problem continues. I also talked on phone to some of you, but then from others I get emails saying I talk to you when I did not. <br/>
<br/>
I think what is happening is, DEA taps my phone and puts a virus on my email. They even have someone impersonating me on phone! They trying to trick us into screwing up and bust us all.<br/>
<br/>
So, I am calling a LOCKDOWN. Stop all sales IMMEDIATELY. There will be no more deliveries until further notice. Discard all supplies smaller than 50 gram. Anything bigger, hide IMMEDIATELY. Only four of you should have anything bigger than 50 gram right now anyway, I will have Leo contact you directly. <br/>
<br/>
Those of you on payroll will still get your money for tonight, don’t worry. Those of you on commission or resale, DO NOT TRY TO MAKE ONE LAST SALE. DISCARD product, understood? THAT IS ORDER. You try to sell anything more tonight, you will regret it. <br/>
<br/>
I will contact each of you IN PERSON, FACE TO FACE, to tell you when this is over. Until then, LOCKDOWN. <br/>
<br/>
That is all. Be safe.<br/>
-Sergey
</div>

<p>
And now Danny was watching the fallout from Sergey’s decree, wishing he had a bag of buttered popcorn and a box of Milk Duds.
</p>

<div class="computer email">
From: Jimmy J &lt;rebelyeller88@gmail.com&gt;<br/>
Subject: RE: Lockdown<br/>
Sergey, I can’t just ditch my stash, man. I got a half an ounce here, it’ll make over half a G on the street pure tonight, even more if I cut it. I got a shorty to feed, man. I need the money. Don’t do this.
</div>

<div class="computer email">
From: Booty Fresh &lt;reggiereggie123@1and1email.com&gt;<br/>
Subject: RE: Lockdown<br/>
Uh, boss, I’m sitting here with a suitcase full of cash ready to make an exchange with Silvio’s guys over at the marina. You tellin me you want me to cancel on them? They not gonna be happy.
</div>

<div class="computer email">
From: 4 Shizzy &lt;4shizzy@yahoo.com&gt;<br/>
Subject: O NO U DINT!<br/>
Sergey dog u know u my bro but there is NO WAY ur callin lockdown when im sittin on a motherfucking kilo. Send me some boys stat, i got a guy in portland gonna take this shit off my hands and i really dont wanna deal wit him all by my lonesome.
</div>

<div class="computer email">
From: Jimmy J &lt;rebelyeller88@gmail.com&gt;<br/>
Subject: RE: O NO U DINT!<br/>
At least he’s letting you keep your stash, Shiz. He wants the rest of us to just throw everything away.
</div>

<div class="computer email">
From: Leo &lt;leonya@pash.ly&gt;<br/>
Subject: RE: O NO U DINT!<br/>
4 Shizzy do NOT move that batch to Portland! I will send Leo to buy it back from you IN PERSON. Booty, I will meet with Silvio's men myself tonight. Where are you right now? Are you at marina yet?<br/>
-Sergey
</div>

<div class="computer email">
From: Miguel &lt;mg323329@msn.com&gt;<br/>
Subject: RE: O NO U DINT!<br/>
¡Booty Fresh no le diga donde usted esta, el podria ser un impostor!
</div>

<div class="computer email">
From: 4 Shizzy &lt;4shizzy@yahoo.com&gt;<br/>
Subject: RE: O NO U DINT!<br/>
Yo Miguel’s right. How do we know ur the real Sergey?
</div>

<div class="computer email">
From: Jimmy J &lt;rebelyeller88@gmail.com&gt;<br/>
Subject: RE: O NO U DINT!<br/>
Hey that’s a good point. How do we even know it was the real Sergey that called lockdown? I bet this is all just some other crew trying to fuck with us. Screw that, I ain’t throwing away shit.
</div>

<p>
As Danny read the emails coming in, he did his best to refrain from guffawing like a tickled hyena. He failed.
</p>
<p>
“Things going according to plan?” Jason asked him.
</p>
<p>
“I think we broke the mob!” Danny chortled.
</p>
<p>
Jason took a deep breath. “You feeling ready to go in?” he asked.
</p>
<p>
Danny gave a nod. “Don’t get us killed, okay?”
</p>
<p>
“Let me do all the talking,” said Jason, “and I think we’ll be alright. Now, you’re sure we got all my insurance papers and license info out of here back on Pill Hill?”
</p>
<p>
“Yep, I left everything with that Natalie woman,” Danny nodded. “This car’s as clean as a hard drive inside a tokamak.”
</p>
<p>
Jason blinked at him.
</p>
<p>
“It’s, um, it’s <em>clean</em>, is what I'm getting at,” Danny clarified. “There’s no trace of your identity in here.”
</p>
<p>
“Good. I don’t want a repeat of what happened to Tina. Maybe we should slap some mud on my license plate or something, too?”
</p>
<p>
“Nah,” said Danny. “That won’t be necessary.”
</p>
<p>
“Why not? Because you don’t think the Russian mob can hack into the Department of Motor Vehicles?”
</p>
<p>
“No. Because you don’t have a front plate, and half of your back plate is currently a bullet hole.”
</p>
<p>
“Oh,” Jason said with a frown. “Alright. Well, then. Let’s get started.”
</p>
<p>
Jason turned the Navigator’s ignition. But before driving, he first ran his hands through his hair and ruffled up his gelled gray strands until they looked spastic and unkempt. He moved his head to take a look at himself in the Navigator’s rearview mirror, drew several deep, long breaths, and stared deeply into his own eyes. He kept his gaze for almost a minute, and in that time his face changed very subtly, just at the threshold of Danny’s perception. 
</p>
<p>
Danny found the prolonged silence awkward. “We gonna go?” he asked innocently.
</p>
<p>
Jason turned his face back at Danny, and glared at him contemptuously. His wrinkle-framed eyes looked dark. Brooding. Strong. And <em>mean</em>. “I told you to keep your mouth shut!” Jason snarled with a voice half an octave lower than usual. “Don’t make me tell you again.” With that, he decisively set his face forward and put the car into gear.
</p>
<p>
They drove along a small gray road that served as a tributary for East Marginal Way. The road wound through the busy spaces between the fulfillment houses, abuzz with workmen loading boxes onto trucks. The car drove slowly, adhering carefully to the route on Jason’s GPS unit. The activity around them dwindled as they headed deeper into the industrial complex. 
</p>
<p>
They reached the tall weed-lined back fence of the property, and rounded a corner to a long, wide alley. Along the back fence stood dumpsters and a handful of parked cars. A few poorly maintained streetlamps created islands of dim, shadow-laden visibility in the long straight stretch of darkness.
</p>
<p>
The headlights of the SUV illuminated the dark figure of a man far in the alley, sitting at the bottom of a flight of metal stairs affixed to the brick exterior of the building. When the headlights fell on him, he rose and moved to stand in the car’s path. He was a muscular, well-built black man, sporting impressive dreadlocks. In his hand he openly carried a complex-looking gun, blocky and rectangular with a wiry protrusion on its back and a very long ammo cartridge extending down from its pistol grip.
</p>
<p>
Jason showed no apprehension. He rolled the Navigator forward, pulled to a stop just a few yards short of the dreadlocked man, and turned on the car’s cabin lights.
</p>
<p>
“Private property, guys,” the black man said clearly and forcefully, his eyes glowing starkly in the SUV’s headlights. “Turn around.” Jason cut the engine and stepped out of the car, slowly but confidently, making sure to keep his hands visible. 
</p>
<p>
The guard lifted the large blocky gun. “You got ‘til the count of three. One…”
</p>
<p>
Jason stood beside the car and said, “Eugene’s been shot.”
</p>
<p>
The man’s eyes widened. “What?” he asked grimly.
</p>
<p>
“The lab had heavy night security,” Jason said, his voice gritty and cold. “Things got really ugly back there.” 
</p>
<p>
“The bitch said they had nothing,” the man said tensely.
</p>
<p>
“The bitch lied,” Jason replied without missing a beat. “Eugene’ll be alright. Sergey’s got someone patching him up right now. But we barely got out alive.”
</p>
<p>
“Who the fuck are you?” 
</p>
<p>
“They call me Numbers,” Jason told him steadily. “And that’s Diggitty in the car. Listen, would you mind putting the piece down? I’ve already been shot at enough tonight. Look at my ride, man. I’ve had to drive around in that thing all night.”
</p>
<p>
The guard kept the firearm aimed squarely at Jason, but after a glance at the car, his stance relaxed. “Why are you here?”
</p>
<p>
Jason answered, “We have the vial.” Moving very slowly, he withdrew the small tube from his jacket pocket.
</p>
<p>
The guard lowered the gun.
</p>
<p>
“I thought it had to be on ice,” he said.
</p>
<p>
“It does,” said Jason. “It’s melting as we speak. We have to hurry. The girl will know what to do with it. Is she alright?”
</p>
<p>
“She’s been crashing for like a week straight. But she’s fine,” said the guard.
</p>
<p>
“Who’s watching her?” asked Jason.
</p>
<p>
“Just Rex,” replied the guard. 
</p>
<p>
Jason reached back into the car, pulled out the keys, and rounded the front of the SUV. The guard was reluctant to let him pass. “I better call the boss-man about this,” he said.
</p>
<p>
“Haven’t you been seeing the emails?” Jason reminded him. “He burned his phone and called lockdown. No cellphone or email contact. He says the feds are monitoring our communications. Tonight of all nights, right?”
</p>
<p>
The guard said nothing, mentally weighing his options.
</p>
<p>
“Look, no offense, man, but we got to get this thing in there stat,” said Jason. “It’s rotting as we speak.”
</p>
<p>
The guard paused for a few seconds. Finally, grudgingly, he said, “Alright. Go on.”
</p>
<p>
Jason proceeded toward the metal stairs behind the guard.
</p>
<p>
Danny hopped out of the Navigator. He reached into the back seat, pulled out his HERF gun, and hurried to catch up toward Jason.
</p>
<p>
“Whoa whoa whoa!” barked the guard. “Just what the hell is that?” The dreadlocked man’s fierce eyes locked onto Danny.
</p>
<p>
Danny froze. He stood there, facing the guard, carrying the HERF gun slung over one shoulder, still wearing Natalie’s oversized floral-print sweatshirt.
</p>
<p>
“It’s… a, um… bio… interferometric… decalibrator… for asymptotic percolation of…” he began to squeak out.
</p>
<p>
Jason immediately jumped in. “Please cut Diggitty some slack. He’s a little… slow, if you know what I mean. Actually, slow’s not even right. He’s great with machines and computers, but you make him talk to a human being and he practically pisses his pants.”
</p>
<p>
Danny tried to say something, but couldn’t decide on what. His feelings told him to argue but his brain told him to play into Jason’s improv role. He ended up just opening and closing his mouth a few times with a scared and hurt expression, which coincidentally made a believable display of mental deficiency.
</p>
<p>
The black man looked Danny up and down, and his hostile expression faded. “This one buddy of mine back in school, he had a kid brother like that. Autistic, right?”
</p>
<p>
“Yeah,” said Jason. “Asperger’s, actually, but close. Poor guy.”
</p>
<p>
“Dude would have to have something wrong with his brain to wear a shirt like that,” he said. A condescending smile crossed his face. “What’s that you got for us, Diggitty? Is that equipment for the lab?” the guard asked in an overly sweet tone normally reserved for pets and small children.
</p>
<p>
Danny nodded fearfully and complacently. Despite actually being a few inches taller than the guard, he felt like a tiny thing.
</p>
<p>
The man waved him through. “Alright, go do your thing.”
</p>
<p>
Danny walked sheepishly past him to join Jason. 
</p>
<p>
The black metal stairs ran straight along the outside of the building’s brick face. Underneath the staircase was a set of large heavy double doors. The stairs topped off at a corrugated landing, where a single reinforced metal door with several keyholes awaited them.
</p>
<p>
Jason ascended the long stairs and knocked. Locks clicked open, and the door swung inward.
</p>
<p>
“Who the hell are you?” came a croaking, grizzled male voice from inside.
</p>
<p>
The door opened to a dimly lit office room, illuminated solely by the light of a monitor. The room was dominated by a desk, mostly empty save for the computer and some random papers. The wall along the desk was built of plate glass windows overlooking a large dark area. The wall adjacent to the door held a tiny bathroom. Across from the entrance was a pale blue door, apparently the only other way out of the room. 
</p>
<p>
“You’re Rex, right?” said Jason. “Sergey sent us. We’ve got stuff for the lab.”
</p>
<p>
In front of the computer, in a rickety wheelie-chair, sat a scrawny man with long, stringy dirty blond hair, wearing cowboy boots and a denim jacket. He didn’t seem old, but his pale skin looked far too wrinkled and pocked for his age. On the desk next to him, beside a pair of earbud headphones connected to the computer, sat his firearm, the same kind of complex, blocky handgun held by the guard outside.
</p>
<p>
“Drop your shit off over there,” said the scrawny blond man, absentmindedly gesturing to a corner of the desk. “I’ll take it downstairs in the morning.”
</p>
<p>
“Actually, Rex, this kind of needs the girl’s immediate attention,” Jason said. He showed him the vial. 
</p>
<p>
Rex bolted forward excitedly in his chair. 
</p>
<p>
“It’s not doing too good,” said Jason, entering the room. Danny followed, closing the front door behind him. “It’s been out of a freezer for a couple hours now, and it’s beginning to rot. The girl needs to look at it, like, right now.”
</p>
<p>
“I’ll wake her up,” said Rex. 
</p>
<p>
Still sitting in his wheelie-chair, Rex rolled over to the far wall and flipped a light switch. In the dark space beyond the wide windows, large parabolic metal lighting fixtures hanging from the ceiling flickered to life. 
</p>
<p>
The gymnasium-style lights illuminated a concrete floor twenty feet below, between walls of cinder-block and brick. The industrial space was big enough for a small warehouse or machine shop, and extended beneath the overhanging office. Packing peanuts and torn-open cardboard boxes lay strewn mindlessly around the floor. Throughout the room was a widely spread, haphazardly arranged array of chemistry and biology equipment, including racks of beakers and tubes, warning-labeled canisters of liquids, and machinery that looked like standalone dishwashers, ovens, a small refrigerator, and a large water-cooler.
</p>
<p>
The blond man stomped loudly on the floor. The sharp pounding of his boot resounded through the industrial space below the office.
</p>
<p>
“Rise and shine, princess!” he called out. 
</p>
<p>
A faint shuffling noise rose from somewhere beneath the floor.
</p>
<p>
“Come on, get up! You got company!” he yelled, and stomped some more.
</p>
<p>
“Fuck off,” a young woman’s voice groaned from below.
</p>
<p>
“Move it, bitch! You know the drill,” he commanded. “Out where I can see you.”
</p>
<p>
 There was movement among the torn cardboard and packing peanuts below. Out from the space underneath the office room emerged a small Asian girl. She was dressed in an ill-fitting t-shirt, sweatpants, and bunny slippers. She had a bruised lip, but otherwise seemed unhurt.
</p>
<p>
She walked to a corner of the factory room clearly visible from the open windows of the office above. 
</p>
<p>
“Good girl! Stay!” Rex shouted down to her. To Jason, he calmly said, “Go on in. She’ll behave herself.”
</p>
<p>
Jason opened the pale blue door on the other side of the room, revealing an interior stairwell leading downward. Behind them, Rex put his headphone buds back into his ears and resumed watching the video on his computer. Danny followed Jason down the open stairwell to the factory floor below.
</p>
</div>
