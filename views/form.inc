<?php

if (isset($vars['errors'])) {
    html::errors($vars['errors']);
}

?>
<form action="" method="post">
<fieldset><legend><?=lang::translate('Fill out the contact form')?></legend>
<label for="title"><?=lang::translate('Title')?></label><br />
<input type="text" name="title" size="<?=HTML_FORM_TEXT_SIZE ?>" value="<?=@$_POST['title']?>" />
<br />
<label for="email"><?=lang::translate('Your email')?></label><br />
<input type="text" name="email" size="<?=HTML_FORM_TEXT_SIZE ?>" value="<?=@$_POST['email']?>" />
<br />
<?php

if (config::getModuleIni('mail_form_captcha')) {
    echo html::labelClean('captcha', captcha::createCaptcha());
    echo html::textClean('captcha');
}

?>

<label for="content"><?=lang::translate('Enter your message')?></label><br />
<textarea name="content" cols="<?=HTML_FORM_TEXTAREA_WT ?>" rows="<?=HTML_FORM_TEXTAREA_HT ?>" ><?=@$_POST['content']?></textarea>
<label for="submit">&nbsp;</label>
<br />
<input type="submit" name="mail_form_submit" value="<?=lang::translate('Submit')?>" />
<br />
</fieldset>

</form>

