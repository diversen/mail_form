<?php

if (isset($vars['errors'])) {
    view_form_errors($vars['errors']);
}

?>
<form action="" method="post">
<fieldset><legend><?=lang::translate('mail_form')?></legend>
<label for="title"><?=lang::translate('mail_form_title')?></label><br />
<input type="text" name="title" size="<?=HTML_FORM_TEXT_SIZE ?>" value="<?=@$_POST['title']?>" />
<br />
<label for="email"><?=lang::translate('mail_form_email')?></label><br />
<input type="text" name="email" size="<?=HTML_FORM_TEXT_SIZE ?>" value="<?=@$_POST['email']?>" />
<br />
<?php

if (config::getModuleIni('mail_form_captcha')) {
    echo html::labelClean('captcha', captcha::createCaptcha());
    echo html::textClean('captcha');
}

?>

<label for="content"><?=lang::translate('mail_form_content')?></label><br />
<textarea name="content" cols="<?=HTML_FORM_TEXTAREA_WT ?>" rows="<?=HTML_FORM_TEXTAREA_HT ?>" ><?=@$_POST['content']?></textarea>
<label for="submit">&nbsp;</label>
<br />
<input type="submit" name="mail_form_submit" value="<?=lang::translate('mail_form_submit')?>" />
<br />
</fieldset>

</form>

