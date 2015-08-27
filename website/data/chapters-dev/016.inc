<div class="chapsection">
<p>
<span class="caplead">Once upon a time, there stood a mighty city</span> of alabaster towers and golden spires. Envious of its majesty, a warlord from Byzantium cast his covetous eye upon it. 
</p>
<p>
And so the city’s watchmen saw the dust of marching boots rise above the surrounding farmland. Temples and palaces trembled from the rumble of advancing footfall. Thousands of iron-helmed soldiers encircled the city. Trebuchets were erected upon hilltops, and battering rams hoisted to the gates. The Byzantine General called out a demand for unconditional surrender.
</p>
<p>
A city herald shouted to the invaders to go home and save themselves.
</p>
<p>
Many times had this city known war, but never had it fallen. Its marble walls were strong, but the city’s true defenses rested in a unique weapon: a corps of elite spies. Armed solely with subterfuge, these cunning operatives crushed entire armies without firing a single arrow.
</p>
<p>
The spies’ methods were simple: when under siege, they disguised themselves as the attacker’s messengers and pages, and fed a General and his lieutenants false battlefield reports, causing the enemy to maneuver into traps. Sometimes, they bribed lieutenants to betray their General, thus transforming a rear guard or flank defense into a scythe which, by surprise and position, reaped entire legions of the enemy’s own troops. Often, the spies would combine these techniques to devastating effect &mdash; convincing a General that a lieutenant had been bribed, thereby tricking him into executing loyal men; or sending two lieutenants falsified orders, telling each that the other was a turncoat, leaving the General to watch helplessly as two of his own companies slaughtered each other with no way to tell who, if anyone, had truly defected.
</p>
<p>
The Byzantine General knew the danger. He nonetheless vowed to attack at dawn, and withdrew to his tent.
</p>
<p>
There he sat, deep in thought, devising a battle plan. It had to operate over a network of untrustworthy pages. It had to account for possible treason, yet remain resilient against false alarms. And above all else, it had to end in victory.
</p>
<p>
Fortunately, the Byzantine General had downloaded a PDF of an article by Lamport, Shostak, and Pease in the July 1982 issue of <em>Transactions on Programming Languages and Systems</em> by the Association for Computing Machinery. He implemented a recursive vote-driven decision algorithm with certificate-based authentication. The city was razed, its gold was plundered, and its name was erased from history. The end.
</p>

<hr/>

<p>
“Wait, <em>what</em>?” said Jason.
</p>
<p>
“I know, right? It sounds inefficent. But you can implement the recursion with a hierarchical distribution scheme!” Danny explained. “The runtime is just O-of-n-log-n. Pretty cool, huh?”
</p>
<p>
Jason shook his head. “I think you lost me somewhere between ‘trebuchet’ and ‘algorithm’.”
</p>
<p>
“It’s an extended metaphor,” Danny explained. “We learn about it in graduate seminars on network security. The pageboys are network connections, the lieutenants are servers, and the battle plan is a computer program.”
</p>
<p>
“And the spies are hackers, right?” Jason said.
</p>
<p>
“Of course,” said Danny. “And the hackers can inject messages into your network, or even take control of your servers.”
</p>
<p>
“And what’s is the city supposed to be?” Jason asked.
</p>
<p>
“It’s… um… Actually, I have no idea.”
</p>
<p>
“The city’s got to represent something.”
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
They sat in Jason’s bullet-pocked Lincoln Navigator, parked behind a chain-link fence in a gravel-strewn lot along Seattle’s southward industrial expanse. Around them sprawled blocks of squat storage spaces known as “fulfillment houses”, the integral middlemen who ensured that every cardboard-boxed package from Amazon or Microsoft or Nordstrom would get to its delivery address. To the north loomed the immense steel cranes of the Port of Seattle. This sector of the city was alive even at this time of night; the cranes swung over cargo ships, the railroad rumbled, and trucks docked in loading zones like bees at a hive. Underlying the Emerald City’s success as a hub of technology was the geography of Elliott Bay. She was a port city, and every night ten million consumer goods had to roll out by sunrise.
</p>
<p>
Danny sat in the passenger seat, looking at his cellphone and giggling. Moshen was sending him forwards of every email, keeping him in the loop. Danny had a front-row seat to the chaos that his teammates were sowing at that very moment.
</p>

<div class="computer email">
From: Eugene &lt;eugene@pash.ly&gt;<br/>
Subject: Phone burned<br/>
Hey guys. Lost my phone. Sorry. Burn the number. 
</div>

<p>
That email had been real. Eugene had sent it a half hour prior. It was delivered to a long list of recipients, many with Spanish names, many just initials, and a few with monikers like “4 Shizzy” or “Wheel Bone” or “Booty Fresh”.
</p>

<div class="computer email">
From: Eugene &lt;eugene@pash.ly&gt;<br/>
Subject: Phone NOT burned. WTF?<br/>

Guys, I DID NOT send that last email. My phone is fine. Who sent that?
</div>

<p>
That had been the first of the forged emails, sent to the same distribution list as Eugene’s real one. 
</p>
<p>
“Why would you tell them that?” Jason had asked.
</p>
<p>
“The trick to inducing a Byzantine failure mode is to get the nodes to trust messages that they shouldn’t, and to distrust messages that they should,” Danny explained. “Part of that involves casting doubt on the messages that are intended to maintain the cohesion of the message distribution system itself. In PKE, we’d call this a certificate reissue forgery.”
</p>
<p>
“But now they know there’s a hacker among them,” Jason said.
</p>
<p>
“Let them. It sows distrust among the ranks.”
</p>

<div class="computer email">
From: Eugene &lt;eugene@pash.ly&gt;<br/>
Subject: Phone burned. Burn this email address.<br/>
I lost my phone and some asshole who found it is pretending to be me. Burn my number AND ignore all other emails from this address. It was just a burner phone, nothing to worry, didn’t have annything important on it.. Will change my email password. For now if you want to talk to me, call Leo.
</div>

<p>
“If he changes his password…” said Jason.
</p>
<p>
“Won’t matter at all,” Danny assured. “We’re <em>inside</em> the mail system. See, when you log in to your email, you’re identifying yourself to a mail server. We’re pretending to <em>be</em> a mail server, and claiming that Eugene &mdash; or Sergey, or whoever &mdash; is logged in to us. Other servers believe us, and distribute our messages as though they came from him. Mind you, a good system administrator would install verification systems &mdash; SPF checks, DKIM, that kind of thing &mdash; to prevent spoof attacks like this. But these Russian guys are using some pretty shady overseas hosting solutions, and it looks like their service providers aren’t exactly top talent.”
</p>

<div class="computer email">
From: Sergey &lt;sergey@pash.ly&gt;<br/>
Subject: Phone is fine but email is hacked<br/>
Guys, this is Sergey. Look, Eugene's phone is fine, we have it right here. But obviously someone got into his email.<br/>
-Sergey
</div>

<p>
Fake as hell. Danny made sure that Sergey himself would be in the <span class="computer">To:</span> list. He would see this message coming from his own email account.
</p>

<div class="computer email">
From: Sergey &lt;sergey@pash.ly&gt;<br/>
Subject: I DID NOT SEND LAST EMAIL<br/>
This last emial saying Eugenes phone is fine, this was not me. DO NOT CALL EUGENE, DO NOT EMAIL EUGENE. BURN EUGENES CONTACT INFO RIGHT NOW. SOS.
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
Real. Of course this 4 Shizzy person hadn’t gotten through to Eugene &mdash; the Russian’s SIM card was still in Danny’s pocket. But this email gave the guys an idea…
</p>

<div class="computer email">
From: X D &lt;xavierdaniels1989@yahoo.com&gt;<br/>
Subject: Just talked to Eugene <br/>
Dunno what all the craziness is all about, I just taked to Eugene on the fone and he seems fine.
</div>

<p>
Fake. X D was some random name from the Russians’ distribution list. The Russians responded with…
</p>

<div class="computer email">
From: Sergey &lt;sergey@pash.ly&gt;<br/>
Subject: Re: Just talked to Eugene<br/>
Has anyone else called Eugene? Whoever you are talking to IS NOT EUGENE. EUGENE IS HERE WITH ME. BURN ALL EUGENE CONTACT INFO RIGHT NOW. THAT IS ORDER!!! If you want to talk to Eugene, call Leo or me.
</div>

<p>
Real. Danny’s team followed it with another spoof from X D.
</p>

<div class="computer email">
From: X D &lt;xavierdaniels1989@yahoo.com&gt;<br/>
Subject: RE: Just talked to Eugene <br/>
Sergey, what gives? I talked to you on the phone ten minutes ago, and you said everything is okay.
</div>

<p>
Sergey’s real response was:
</p>

<div class="computer email">
From: Sergey &lt;sergey@pash.ly&gt;<br/>
Subject: RE: Just talked to Eugene <br/>
What? You talked to me on phone??? No we didn’t. 
</div>

<p>
The hacker crew chased it with a series of forged messages from Sergey’s minions.
</p>

<div class="computer email">
From: X D &lt;xavierdaniels1989@yahoo.com&gt;<br/>
Subject: RE: Just talked to Eugene <br/>
Yeah we did.
</div>

<div class="computer email">
From: 4 Shizzy &lt;4shizzy@yahoo.com&gt;<br/>
Subject: RE: Just talked to Eugene <br/>
Yeah man. Just got off the phone with u 2, u sounded a little weird.
</div>

<div class="computer email">
From: Miguel &lt;mg323329@msn.com&gt;<br/>
Subject: RE: Just talked to Eugene <br/>
Sergey just called me and told me to make delivery to new address downtown. He sounded strange. I go check out the place, it's right next to police station! Something about this is all wrong.
</div>

<p>
And in response, Sergey delivered his own coup de grâce: 
</p>

<div class="computer email">
From: Leo &lt;leonya@pash.ly&gt;<br/>
Subject: LOCKDOWN<br/>
This is Sergey. I using Leo email because Leo not having any problems, thanks God. I do not know what is going on. Somebody send out emails from my account, pretend to be me and gives strange orders. And I get emails saying I talk to you on phone, when I did not. <br/>
<br/>
I think what is happening is, DEA taps my phone and puts a virus on my email. They even have someone impersonating me on phone! They trying to trick us into screwing up and bust us all.<br/>
<br/>
So, I am calling a LOCKDOWN. Stop all sales IMMEDIATELY. Discard all supplies smaller than 50 gram. Anything bigger, hide it. Only four of you should have anything bigger than 50 gram anyway, I will have Leo contact you.<br/>
<br/>
Those of you on payroll will still get your money for tonight. Those of you on commission, DO NOT TRY TO MAKE ONE LAST SALE. DISCARD product, understood? THAT IS ORDER. You try to sell anything more tonight, you will regret it. <br/>
<br/>
I will contact each of you IN PERSON, FACE TO FACE, to tell you when this is over. Until then, LOCKDOWN. <br/>
<br/>
Be safe.<br/>
-Sergey
</div>

<p>
And now Danny was watching the fallout from Sergey’s decree, wishing he had some popcorn and Milk Duds.
</p>

<div class="computer email">
From: Jimmy J &lt;rebelyeller88@gmail.com&gt;<br/>
Subject: RE: Lockdown<br/>
Sergey, I can’t just ditch my stash, man. Customers are lined up. I got a shorty to feed. Don’t do this.
</div>

<div class="computer email">
From: Booty Fresh &lt;reggiereggie123@1and1email.com&gt;<br/>
Subject: RE: Lockdown<br/>
Boss, I’m sitting here with a suitcase full of cash ready to make an exchange with Silvio’s guys at the marina. You tellin me you want me to cancel on them? They not gonna be happy.
</div>

<div class="computer email">
From: 4 Shizzy &lt;4shizzy@yahoo.com&gt;<br/>
Subject: O NO U DINT!<br/>
Sergey dog u know u my bro but there is NO WAY ur callin lockdown when im sittin on a motherfucking half-ki. Send me some boys stat, i got a guy in portland gonna take this shit off my hands and i really dont wanna deal wit him all by my lonesome.
</div>

<div class="computer email">
From: Jimmy J &lt;rebelyeller88@gmail.com&gt;<br/>
Subject: RE: O NO U DINT!<br/>
At least he’s letting you keep your stash, Shiz. He wants the rest of us to just throw everything away.
</div>

<div class="computer email">
From: Leo &lt;leonya@pash.ly&gt;<br/>
Subject: RE: O NO U DINT!<br/>
4 Shizzy do NOT move that batch to Portland! I will send Leo to buy it back from you IN PERSON. Booty, I will meet with Silvio's men myself tonight. Are you at marina yet?<br/>
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
Jason took a breath. “You feeling ready to go in?”
</p>
<p>
Danny nodded. “Don’t get us killed, okay?”
</p>
<p>
“Let me do all the talking,” said Jason, “and I think we’ll be alright. Now, you’re sure we got all my insurance papers and license info out of here back on Pill Hill?”
</p>
<p>
“Yep, I left everything with Natalie,” Danny said. “This car’s as clean as a hard drive inside a tokamak.”
</p>
<p>
Jason blinked at him.
</p>
<p>
“It’s, um, it’s <em>clean</em>, is what I'm getting at,” Danny clarified. “There’s no trace of your identity here.”
</p>
<p>
“Good. I don’t want a repeat of what happened to Tina. Maybe we should slap mud on my license plate or something, too?”
</p>
<p>
“That won’t be necessary,” said Danny.
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
Jason turned the Navigator’s ignition. But before driving, he ran his hands through his hair and ruffled up his gelled strands. He looked at himself in the Navigator’s rearview mirror, drew several long breaths, and stared deeply into his own eyes. He kept his gaze for almost a minute, and in that time his face changed subtly. 
</p>
<p>
Danny found the prolonged silence awkward. “We gonna go…?”
</p>
<p>
Jason turned to Danny, and glared at him contemptuously. His wrinkle-framed eyes looked dark. Brooding. Strong. And <em>mean</em>. “I told you to keep your mouth shut!” he snarled with a voice half an octave lower than usual. “Don’t make me tell you again.” With that, he set his face forward and put the car into gear.
</p>
<p>
They drove along a small gray road that served as a tributary for East Marginal Way. The road wound through the busy spaces between the fulfillment houses, abuzz with workmen loading boxes onto trucks. The car drove slowly, adhering carefully to the route on Jason’s GPS unit. The activity around them dwindled as they headed deeper into the industrial complex. 
</p>
<p>
They reached the tall weed-lined back fence of the property, and rounded a corner to a long, wide alley. Along the back fence stood dumpsters and a handful of parked cars. A few poorly maintained streetlamps created islands of dim, shadow-laden visibility in the long stretch of darkness.
</p>
<p>
The headlights of the SUV illuminated the dark figure far in the alley, sitting at the bottom of a flight of metal stairs affixed to the brick exterior of the building. When the headlights fell on him, he moved to stand in the car’s path. He was a muscular, well-built black man, sporting shoulder-length dreadlocks. He openly carried a complex-looking gun, blocky with a wiry protrusion on its back and a long ammo cartridge extending down from its grip.
</p>
<p>
Jason showed no apprehension. He pulled to a stop just a few yards short of the man, and turned on the car’s cabin lights.
</p>
<p>
“Private property!” the guard said forcefully, his eyes glowing starkly in the SUV’s headlights. “Turn around.” Jason cut the engine and stepped out slowly, keeping his hands visible. 
</p>
<p>
The guard lifted the blocky gun. “You got ‘til the count of three. One…”
</p>
<p>
Jason stood beside the car and said, “Eugene’s been shot.”
</p>
<p>
The man’s eyes widened. “What?”
</p>
<p>
“The lab had heavy night security,” said Jason, his voice gritty. “Things got ugly back there.” 
</p>
<p>
“The bitch said they had nothing,” the man said tensely.
</p>
<p>
“The bitch lied,” said Jason. “Eugene’ll be alright. Sergey’s got someone patching him up. But we barely got out alive.”
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
“We have the vial.” Moving very slowly, he withdrew the small tube from his pocket. “The girl will know what to do with it. Is she alright?”
</p>
<p>
The guard lowered the gun. “She’s been crashing for like a week straight. But she’s fine.”
</p>
<p>
“Who’s watching her?” asked Jason.
</p>
<p>
“Just Rex,” replied the guard. “Look, I gotta call the boss-man about you.”
</p>
<p>
“Haven’t you been seeing the emails?” Jason said. “He burned his phone and called lockdown. No cellphone or email. He says the feds are monitoring our communications.”
</p>
<p>
The guard said nothing, weighing his options.
</p>
<p>
“Look, no offense, man, but we got to get this thing in there stat,” said Jason. “It’s supposed to be in deep-freeze.”
</p>
<p>
The guard paused. Grudgingly, he said, “Alright. Go on.”
</p>
<p>
Jason proceeded toward the metal stairs behind the guard.
</p>
<p>
Danny hopped out of the Navigator. He pulled out his HERF gun and hurried to catch up toward Jason.
</p>
<p>
“Whoa whoa whoa!” barked the guard. “Just what the hell is that?” The dreadlocked man’s fierce eyes locked onto Danny.
</p>
<p>
Danny froze. He stood facing the guard, carrying the HERF gun slung over one shoulder, still wearing Natalie’s oversized floral-print sweatshirt.
</p>
<p>
“It’s… a, um… bio… interferometric… decalibrator… for asymptotic percolation of…” he began to squeak out.
</p>
<p>
Jason cut him off. “Please cut Diggitty some slack. He’s a little… slow, if you know what I mean. Actually, slow’s not right. He’s great with machines and computers, but you make him talk to a human being and he practically pisses his pants.”
</p>
<p>
Danny tried to say something. His feelings told him to protest but his brain told him to play into Jason’s improv role. He ended up just opening and closing his mouth a few times, which coincidentally made a believable display of mental deficiency.
</p>
<p>
The guard looked Danny up and down, and his hostile expression faded. “This one buddy of mine back in school, he had a kid brother like that. Autistic, right?”
</p>
<p>
“Yeah,” said Jason. “Asperger’s, actually, but close. Poor guy.”
</p>
<p>
“Dude would have to have something wrong with his brain to wear a shirt like that,” he said, and smiled condescendingly. “What’s that you got for us, Diggitty? Is that equipment for the lab?” the guard asked in a tone normally reserved for pets and small children.
</p>
<p>
Danny nodded fearfully. Despite being a few inches taller than the guard, he felt like a tiny thing.
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
The door opened to a dim office room, illuminated solely by a monitor. The room was dominated by a desk, mostly empty save for the computer and some random papers. The wall along the desk was built of plate glass windows overlooking a large dark area. The adjacent wall abutted a tiny bathroom. Across from the entrance was a pale blue door, apparently the only other way out. 
</p>
<p>
“You’re Rex, right?” said Jason. “Sergey sent us. We’ve got stuff for the lab.”
</p>
<p>
In front of the computer, in a rickety wheelie-chair, sat a scrawny man with stringy blond hair, wearing cowboy boots and a denim jacket. He didn’t seem old, but his pale skin looked far too wrinkled and pocked for his age. On the desk next to him, beside a pair of earbud headphones connected to the computer, sat his firearm, the same kind of complex, blocky handgun. “Drop your shit off over there,” he said, absentmindedly gesturing to a corner of the desk. “I’ll take it downstairs in the morning.”
</p>
<p>
“Actually, Rex, this kind of needs the girl’s immediate attention,” Jason said. He showed him the vial. 
</p>
<p>
Rex bolted forward excitedly. 
</p>
<p>
“It’s not doing too good,” said Jason as he entered. Danny followed, closing the front door behind him. “It’s been out of a freezer for a couple hours now. She needs to look at it fast.”
</p>
<p>
“I’ll wake her up,” said Rex. 
</p>
<p>
Rex rolled in his wheelie-chair to the far wall and flipped a light switch. In the dark space beyond the wide windows, large gymnasium-style lighting fixtures hanging from the ceiling flickered to life. 
</p>
<p>
They illuminated a concrete floor twenty feet below, between walls of cinder-block and brick. The industrial space was big enough for a warehouse or machine shop, and extended beneath the overhanging office. Packing peanuts and torn-open cardboard boxes lay strewn around the floor. Throughout the room was a widely spread, haphazardly arranged array of chemistry and biology equipment, including racks of beakers and tubes, warning-labeled canisters of liquids, and machinery that looked like dishwashers, ovens, refrigerators, and water coolers.
</p>
<p>
The blond man stomped loudly. The sharp pounding of his boot resounded through the industrial space below the office.
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
She walked to a corner of the factory clearly visible from the open windows of the office above. 
</p>
<p>
“Good girl! Stay!” Rex shouted down to her. To Jason, he calmly said, “Go on down. She’ll behave herself.”
</p>
<p>
Jason opened the door on the other side of the room, revealing an interior stairwell. Behind them, Rex put his headphone buds back into his ears and resumed a video on his computer. Danny followed Jason down the open stairwell to the factory floor below.
</p>
</div>
